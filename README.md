# PSTryExtend - Photoshop Trial Reset Tool

<img src="https://github.com/FebraS/PSTryExtend/blob/main/assets/pstryextend.png" alt="PS Try Extend" width="250" height="250">

PSTryExtend is a small utility written in C language designed to help users "reset" the trial period of Adobe Photoshop CC 2018. 
&nbsp;This application works by modifying the application.xml file associated with the Photoshop installation, specifically changing the TrialSerialNumber to a new random value.

Important: This tool is provided for educational and personal experimentation purposes. 
Using this tool to circumvent software licensing requirements may violate terms of service or copyright laws. 
Use at your own risk and ensure you understand the implications.

## Application Description
The PSTryExtend application reads the content of the application.xml file located in the Adobe Photoshop CC 2018 installation path. 
After reading the file, it searches for the key string `<Data key="TrialSerialNumber">`. 
If found, the application will replace the next 24 characters after this key string with a random combination of numbers and uppercase letters. 
This change aims to make the software licensing system consider it a new trial installation.

## How to Compile
To compile this application, you will need a C compiler such as GCC (GNU Compiler Collection).

### Ensure you have GCC installed:
If you don't have it yet, you can install it via MinGW.


1. Open Command Prompt:
Navigate to the directory where you saved the main.c file.
2. Run the compilation command:
Use the following command to compile the code:
```
gcc main.c main.res -o pstryextend.exe
```

### How to Use
Once you have successfully compiled the application, follow these steps to use it:

1. **Identify the Target File Path:**
By default, this application assumes the application.xml file is located at: `C:\Program Files\Adobe\Adobe Photoshop CC 2018\AMT\application.xml`
Ensure this path is correct for your Photoshop installation. If not, you will need to modify the `FILE_PATH` define in the source code (main.c) before compiling.

2. **Close Adobe Photoshop CC 2018:**
Make sure Adobe Photoshop CC 2018 is completely closed before running this application.

3. **Run as Administrator (Important!):**
Since this application modifies files in the `C:\Program Files\ directory`, you must run it with administrator privileges.

4. Right-click on the pstryextend.exe you compiled, then select "Run as administrator".

5. **Verification:**
The application will print the message Trial Reset Successfully. if the operation is successful. 
If there are errors (e.g., file not found, no permissions), an error message will be displayed in the console.

6. **Reopen Adobe Photoshop CC 2018:**
After running the application, reopen Adobe Photoshop CC 2018 without internet connetion. 
You may see an option to start a new trial or your trial period may have been extended.

### Warnings:

This tool is specific to Adobe Photoshop CC 2018 and may not work with other versions of Photoshop or other Adobe software.
Irresponsible use may cause issues with your software installation or violate licensing agreements.
