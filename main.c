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

            printf("Digite a data de nascimento do autor: ");
            scanf("%d/%d/%d", &biblioteca[i]->autor.data_nascimento.dia, &biblioteca[i]->autor.data_nascimento.mes, &biblioteca[i]->autor.data_nascimento.ano);
            getchar(); 

            printf("Digite a data em que o livro foi publicado: ");
            scanf("%d/%d/%d", &biblioteca[i]->data_escrita.dia, &biblioteca[i]->data_escrita.mes, &biblioteca[i]->data_escrita.ano);
            getchar(); 

            printf("\nLivro cadastrado com sucesso no slot %d!\n", i+1);
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
    carregarBiblioteca(biblioteca, argv[1]);

    int op=0;
    int id=0;

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
                printf("Digite o ID do livro que deseja deletar: ");
                scanf("%d", &id);
                getchar();
                deletarLivro(biblioteca, id);
                break;
            case 3:
                printf("\nMostrar Livro...\n");
                printf("Digite o ID do livro que deseja visualizar: ");
                scanf("%d", &id);
                getchar();
                mostrarLivro(biblioteca, id);
                break;
            case 4:
                printf("\nEditar Livro...\n");
                 printf("Digite o ID do livro que deseja editar: ");
                scanf("%d", &id);
                getchar();
                editarLivro(biblioteca, id);
                break;
            case 5:
                printf("\nListar Titulos dos Livros...\n");
                listarTitulos(biblioteca);
                break;
            case 6:
                printf("\nFechando... Ate a proxima aventura!\n");
                salvarBiblioteca(biblioteca, argv[1]);
                break;
            default:
                printf("\nOpcao invalida! Escolha uma opcao de 1 a 6.\n");
        }

    } while(op!=6);

    return 0;
}