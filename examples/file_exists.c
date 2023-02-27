#include <stdio.h>
#include <stdlib.h>
#include "../simplec.h"

int main(){

    if (file_exists("file_exists.c") == 0){
        printf("File exists!");
    }
    else {
        printf("File DOES NOT exist");
    }
   
}