#include <stdio.h>

void criptografar(char* str){

    int i;

    for(i=0;str[i]!='\0';i++){

        str[i]= (char)(255 - (unsigned char)str[i]);
    }
}

void descriptografar(char *str){
    int i;

    for(i = 0; str[i] != '\0'; i++){

        str[i] = (char)(255 - (unsigned char)str[i]);
    }
}
