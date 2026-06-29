#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "criptografia.h"
#include "estruturas.h"


void salvarBiblioteca(LivroMagico **biblioteca, const char *nomeArquivo){

    FILE *arquivo;
    int i;

    arquivo = fopen(nomeArquivo, "w");

    if(arquivo == NULL){
    printf("Erro ao abrir arquivo.\n");
    return;
}

    for(i=0;i<100;i++){

        if(biblioteca[i]!=NULL){

            char tituloTemp[100];

            strcpy(tituloTemp, biblioteca[i]->titulo);
            criptografar(tituloTemp);

            fprintf(arquivo, "%d;%s;%s;%d;%d;%d;%d;%d;%d\n",
                    biblioteca[i]->id, tituloTemp,
                    biblioteca[i]->autor.nome,
                    biblioteca[i]->autor.data_nascimento.dia,
                    biblioteca[i]->autor.data_nascimento.mes,
                    biblioteca[i]->autor.data_nascimento.ano,
                    biblioteca[i]->data_escrita.dia,
                    biblioteca[i]->data_escrita.mes,
                    biblioteca[i]->data_escrita.ano);
        }
    }

    fclose(arquivo);
}

void carregarBiblioteca(LivroMagico **biblioteca, const char *nomeArquivo){

    FILE *arquivo;
    LivroMagico *novo;
    int i;

    arquivo = fopen(nomeArquivo, "r");

    if(arquivo == NULL){
    return;
}   
    while(1){

    novo = (LivroMagico*)malloc(sizeof(LivroMagico));

        if(fscanf(arquivo, "%d;%[^;];%[^;];%d;%d;%d;%d;%d;%d",
                    &(novo->id), novo->titulo, novo->autor.nome,
                    &(novo->autor.data_nascimento.dia),
                    &(novo->autor.data_nascimento.mes),
                    &(novo->autor.data_nascimento.ano),
                    &(novo->data_escrita.dia),
                    &(novo->data_escrita.mes),
                    &(novo->data_escrita.ano)) != 9){


                        free(novo); 
                        break;
                }

                descriptografar(novo->titulo);

                    for(i = 0; i < 100; i++){
                    if(biblioteca[i] == NULL){
                        biblioteca[i] = novo;
                        break;
                        }
                    }
        }

        fclose(arquivo);
}
