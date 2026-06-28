
#include<stdio.h>
#include<stdlib.h>

struct Data {
    int dia;
    int mes;
    int ano;
}; 

struct Autor {
    char nome[128];
    struct Data data_nascimento;
};

struct LivroMagico { 
    unsigned int ID; 
    char titulo[200];
    struct Autor autor;
    struct Data data_escrita;
}; 

#define TAM 100

void inicializarVetor(struct LivroMagico **biblioteca[TAM]){
    int i;
    for (i=0; i<100; i++){
        biblioteca[i]=NULL;
    }
}

int main(){

    struct LivroMagico *biblioteca[TAM];

    inicializarVetor(biblioteca);


    return 0;
}