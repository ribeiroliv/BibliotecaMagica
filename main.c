
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