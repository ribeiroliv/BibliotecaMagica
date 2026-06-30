#include<stdio.h>
#include<stdlib.h>
#include "estruturas.h"
#include "livro.h"
#include "arquivo.h"

#define TAM 100



void inicializarVetor(LivroMagico **biblioteca){
    int i;
    for (i=0; i<100; i++){
        biblioteca[i]=NULL;
    }
}

void cadastrarLivro(LivroMagico **biblioteca) {
    int i;
    int flag = 0;

    for (i = 0; i <100; i++) {
        if (biblioteca[i] == NULL) {
            flag = 1;

            biblioteca[i] = ( LivroMagico*) malloc(sizeof( LivroMagico)); 

            printf("Digite o ID do livro: ");
            scanf("%u", &biblioteca[i]->id);
            getchar(); 

            printf("Digite o titulo do livro: ");
            scanf("%199[^\n]", biblioteca[i]->titulo);
            getchar(); 

            printf("Digite o nome do autor: ");
            scanf("%127[^\n]", biblioteca[i]->autor.nome);
            getchar(); 

            printf("Digite o dia de nascimento do autor: ");
            scanf("%d", &biblioteca[i]->autor.data_nascimento.dia);
            printf("Digite o mes de nascimento do autor: ");
            scanf("%d", &biblioteca[i]->autor.data_nascimento.mes);
            printf("Digite o ano de nascimento do autor: ");
            scanf("%d", &biblioteca[i]->autor.data_nascimento.ano);
            getchar(); 

            printf("Digite o dia em que o livro foi escrito: ");
            scanf("%d", &biblioteca[i]->data_escrita.dia);
            printf("Digite o mes em que o livro foi escrito: ");
            scanf("%d", &biblioteca[i]->data_escrita.mes);
            printf("Digite o ano em que o livro foi escrito: ");
            scanf("%d", &biblioteca[i]->data_escrita.ano);
            getchar(); 

            printf("\nLivro cadastrado com sucesso no slot %d!\n", i);
            break; 
        }
    }

    if (flag == 0) {
        printf("Erro: Inventario Cheio! Nao e possivel cadastrar mais livros.\n");
    }
}

int main(int argc, char *argv[]){

    if(argc<2){
        printf("ERRO: Faltou informar o arquivo de save do jogo!\n");
        return 1;
    }

   LivroMagico *biblioteca[TAM];

    inicializarVetor(biblioteca);

    int op=0;

    do {
        printf("\n\nBEM VINDO A BIBLIOTECA MAGIGA!\n\n");
        printf("1. Cadastrar Livro\n2. Deletar Livro\n3. Mostrar Livro\n4. Editar Livro\n5. Listar Titulos dos Livros\n6. Sair\n");
        printf("\nEscolha uma opcao: ");

        scanf("%d", &op);
        getchar();

        switch(op) {
            case 1:
                printf("\nCadastrar livro...\n");
                cadastrarLivro(biblioteca);
                break;
            case 2:
                printf("\nDeletar Livro...\n");
                break;
            case 3:
                printf("\nMostrar Livro...\n");
                break;
            case 4:
                printf("\nEditar Livro...\n");
                break;
            case 5:
                printf("\nListar Titulos dos Livros...\n");
                break;
            case 6:
                printf("\nFechando... Ate a proxima aventura!\n");
                break;
            default:
                printf("\nOpcao invalida! Escolha uma opcao de 1 a 6.\n");
        }

    } while(op!=6);

    return 0;
}