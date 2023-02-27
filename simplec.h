/*
# SimpleC - A *cross-platform header that simplifies your C code and makes processes much easier.
#
# Compile with gcc, because clang has issues with SimpleC which I am trying to resolve!
#
# Since it is not based on the Windows API, it can be called as cross-platform since it uses standard headers that are included on gcc.
#
#
# Command List:
# ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
# create_file(char *filename) : Creates a file in the existing directory.
# file_exists(char *filename) : Checks if a file exists.
# binary_copy(const char *indir, const char *outdir) : Makes a copy of a binary in a specified directory.
# whoami() : A simple wrapper of the whoami executable. It checks the kernel that runs, so it can configure the location of the executable (made possible by nt_whomai() and linux_whoami() )
#^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
# Copyright © 2023 Karapatakis Aggelos
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
# subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
#================================================================================================================================================================================================================
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    #define OS_WINDOWS
    #include <Windows.h>
    #include <Lmcons.h>
#else
    #include <pwd.h>
#endif


// whoami() - a simple whoami wrapper (requires the whoami binary installed on the system)

void whoami(void){
    #ifdef OS_WINDOWS
        char username[UNLEN+1];
        SetConsoleOutputCP(1253); 
        DWORD username_len = UNLEN+1;
        GetUserName(username, &username_len);
        printf("%s", username);

    #else
        char *username = getpwuid(getuid());
        printf("%s", username);
    #endif
}

// file_exists() - as the name says, it checks if the file is accessible and exists. Use it only for files that can be accessible from the system.
int file_exists(const char *filename){

    FILE *buffer;

    if ((buffer == fopen(filename, "r") == 0)){
        return 0;
    }
    else {
        return 1;
    }
    fclose(buffer);
}

// create_file() - as the name says again, it creates a blank file.
int create_file(const char *filename){
    FILE *buffer;

    buffer = fopen(filename, "w+");
    fclose(buffer);

}

// binary_copy() - it copies the contents of a binary to a new one.
int binary_copy(const char *indir, const char *outdir){

    FILE *bufferIn; //buffer input pointer
    FILE *bufferOut; //buffer output pointer
    FILE *targetFile;

    unsigned char Contentbuffer[sizeof(bufferIn)]; //bianry contents buffer
    targetFile = fopen(outdir, "w+");
    fclose(targetFile);
    bufferIn = fopen(indir, "rb");
    bufferOut = fopen(outdir, "wb");


    fwrite(Contentbuffer, sizeof(Contentbuffer),1,bufferOut); //deploy binary contents

    fclose(bufferIn);
    fclose(bufferOut);

}
