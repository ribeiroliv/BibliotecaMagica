#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estruturas.h"

#define TAM 100

/*Essa função auxilia na busca dos livros por id*/
LivroMagico * buscaId(LivroMagico **biblioteca, int id) {
	int i;
	for(i = 0; i < TAM; i++) {
		if(biblioteca[i] != NULL) {
			if(biblioteca[i]->id == id) {
				return biblioteca[i];
			}
		}
	}

	return NULL;

}

/*Essa função implementa busca e exibição do livro por ID*/
void mostrarLivro(LivroMagico **biblioteca, int id) {
	LivroMagico *livro = buscaId(biblioteca, id);

	if(livro != NULL) {
		printf("ID: %d\n", livro->id);
		printf("Titulo: %s\n", livro->titulo);
		printf("Autor: %s\n", livro->autor.nome);
		printf("Data de Nascimento do Autor: %d/%d/%d\n", livro->data_nascimento.dia, livro->data_nascimento.mes, livro->data_nascimento.ano);
		printf("Data de Publicação: %d/%d/%d\n", livro->data_escrita.dia, livro->data_escrita.mes, livro->data_escrita.ano);	
	} else {
		printf("Livro nao encontrado!\n");
	}
}

/*Essa função imprime a lista de todos os livros da biblioteca e seus respectivos IDs*/
void listarTitulos(LivroMagico **biblioteca) {
	int i;
	int bibliotecaVazia = 0;

	for(i = 0; i < TAM; i++) {
		if(biblioteca[i] != NULL) {
			printf("%d. %s\n", biblioteca[i]->id, biblioteca[i]->titulo);
			bibliotecaVazia++;
		}
	}

	if(bibliotecaVazia == 0) {
		printf("Ainda não há livros nessa biblioteca!\n");
	}
}

/*Essa função deleta um livro da biblioteca*/
void deletarLivro(livroMagico **biblioteca, int id) {
	int i;
	int encontrouLivro = 0;

	for(i = 0; i < TAM; i++) {
		if(biblioteca[i] != NULL) {
			if(biblioteca[i]->id == id) {
				encontrouLivro = 1;
				break;
			}
		} 
	}

	if(encontrouLivro != 0) {
		free(biblioteca[i]);
		biblioteca[i] = NULL;
		printf("Livro deletado da biblioteca com sucesso!\n");
	} else {
		printf("Não há livro a ser deletado!\n");
	}
	
}