// GPL-3.0 license
/*
    PSTryExtend/main.c
    
    Copyright (C) 2025  Febra S
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_PATH "C:\\Program Files\\Adobe\\Adobe Photoshop CC 2018\\AMT\\application.xml"
#define KEY_STRING "<Data key=\"TrialSerialNumber\">"
#define SERIAL_LENGTH 24

// Fungsi untuk menghasilkan karakter acak (angka saja)
char generateRandomChar() {
    int r = rand() % 10; // 0-9 for digits
    return '0' + r;
}


int main() {
    FILE *fp;
    long fileSize;
    char *buffer;
    char *pKey;
    int i;

    // Inisialisasi generator angka acak
    srand((unsigned int)time(NULL));

    // Buka file dalam mode baca
    fp = fopen(FILE_PATH, "rb"); // "rb" untuk membaca dalam mode biner
    if (fp == NULL) {
        perror("Error opening file");
        printf("Make sure the file path is correct and you have access permissions.");
        return 1;
    }

    // Dapatkan ukuran file
    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Alokasikan memori untuk menyimpan konten file
    buffer = (char *)malloc(fileSize + 1);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return 1;
    }

    // Baca seluruh konten file ke dalam buffer
    fread(buffer, 1, fileSize, fp);
    buffer[fileSize] = '\0'; // Tambahkan null terminator
    fclose(fp); // Tutup file setelah membaca

    // Cari string kunci
    pKey = strstr(buffer, KEY_STRING);
    if (pKey == NULL) {
        printf("Key string '%s' not found in file.\n", KEY_STRING);
        free(buffer);
        return 1;
    }

    // Geser pointer ke awal 24 karakter yang akan diubah
    pKey += strlen(KEY_STRING);

    // Acak lima angka terakhir
    for (i = SERIAL_LENGTH - 5; i < SERIAL_LENGTH; i++) {
        pKey[i] = generateRandomChar();
    }

    // Buka file kembali dalam mode tulis (akan menimpa file yang sudah ada)
    fp = fopen(FILE_PATH, "wb"); // "wb" untuk menulis dalam mode biner
    if (fp == NULL) {
        perror("Error opening file for writing");
        free(buffer);
        return 1;
    }

    // Tulis kembali seluruh buffer yang telah dimodifikasi ke file
    fwrite(buffer, 1, fileSize, fp);
    fclose(fp); // Tutup file setelah menulis

    printf("Trial Reset Successfully: %s\n");
    
    free(buffer); // Bebaskan memori yang dialokasikan

    return 0;
}
