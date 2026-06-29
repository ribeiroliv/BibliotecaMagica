#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct 
{
    char nome[100];
    Data data_nascimento;
}Autor;

typedef struct{
    int id;
    char titulo[100];
    Autor autor;
    Data data_escrita;
}LivroMagico;


#endif