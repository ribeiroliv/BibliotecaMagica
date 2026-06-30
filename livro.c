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
		printf("Data de Publicacao: %d/%d/%d\n", livro->data_escrita.dia, livro->data_escrita.mes, livro->data_escrita.ano);	
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
void deletarLivro(LivroMagico **biblioteca, int id) {
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

/*Essa função busca o livro pelo ID e permite ao usuário reescrever os seus atributos*/
void editarLivro(LivroMagico **biblioteca, int id) {
	LivroMagico *livro = buscaId(biblioteca, id);
	int campoSelecionado;

	if(livro != NULL) {

		printf("ID: %d\n", livro->id);
		printf("Titulo: %s\n", livro->titulo);
		printf("Autor: %s\n", livro->autor.nome);
		printf("Data de Nascimento do Autor: %d/%d/%d\n", livro->autor.data_nascimento.dia, livro->autor.data_nascimento.mes, livro->data_nascimento.ano);
		printf("Data de Publicacao: %d/%d/%d\n", livro->data_escrita.dia, livro->data_escrita.mes, livro->data_escrita.ano);

		printf("\n");

		printf("Digite o numero correspondente ao campo que deseja editar!\n");

		printf("\n");

		printf("1. ID\n2. Titulo\n3. Nome do autor\n4. Data de nascimento do Autor\n5. Data de publicacao\n6. Todos os campos\n");
		scanf("%d", &campoSelecionado);

		if(campoSelecionado == 1) {
			printf("ID: %d\n", livro->id);

			printf("\n");

			printf("Digite o novo ID:\n");
			scanf("%d", &livro->id);

			printf("ID editado com sucesso!\n");
			printf("%d. %s\n", livro->id, livro->titulo);
		} 

		if(campoSelecionado == 2) {
			printf("Titulo: %s\n", livro->titulo);

			printf("\n");

			printf("Digite o novo Titulo:\n");
			scanf(" %[^\n]", livro->titulo);

			printf("Titulo editado com sucesso!\n");
			printf("%d. %s\n", livro->id, livro->titulo);
		} 

		if(campoSelecionado == 3) {
			printf("Nome do Autor: %s\n", livro->autor.nome);

			printf("\n");

			printf("Digite o novo nome do Autor:\n");
			scanf(" %[^\n]", livro->autor.nome);

			printf("Nome do Autor editado com sucesso!\n");
			printf("%d. %s\n", livro->id, livro->titulo);
			printf("Autor: %s\n", livro->autor.nome);
		} 

		if(campoSelecionado == 4) {
			printf("Data de nascimento do Autor: %d/%d/%d\n", livro->data_nascimento.dia, livro->data_nascimento.mes, livro->data_nascimento.ano);

			printf("\n");

			printf("Digite a nova Data de nascimento do Autor:\n");
			scanf("%d/%d/%d", &livro->data_nascimento.dia, &livro->data_nascimento.mes, &livro->data_nascimento.ano);

			printf("Data de nascimento do Autor editada com sucesso!\n");
			printf("%d. %s\n", livro->id, livro->titulo);
			printf("Data de Nascimento do Autor: %d/%d/%d\n", livro->data_nascimento.dia, livro->data_nascimento.mes, livro->data_nascimento.ano);
		} 

		if(campoSelecionado == 5) {
			printf("Data de publicacao: %d/%d/%d\n", livro->data_escrita.dia, livro->data_escrita.mes, livro->data_escrita.ano);

			printf("\n");

			printf("Digite a nova Data de publicacao:\n");
			scanf("%d/%d/%d", &livro->data_escrita.dia, &livro->data_escrita.mes, &livro->data_escrita.ano);

			printf("Data de publicacao editada com sucesso!\n");
			printf("%d. %s\n", livro->id, livro->titulo);
			printf("Data de Publicacao: %d/%d/%d\n", livro->data_escrita.dia, livro->data_escrita.mes, livro->data_escrita.ano);
		} 

		if(campoSelecionado == 6) {
			printf("ID: %d\n", livro->id);

			printf("\n");

			printf("Digite o novo ID:\n");
			scanf("%d", &livro->id);

			printf("\n");

			printf("Titulo: %s\n", livro->titulo);

			printf("\n");

			printf("Digite o novo Titulo:\n");
			scanf(" %[^\n]", livro->titulo);

			printf("\n");

			printf("Nome do Autor: %s\n", livro->autor.nome);

			printf("\n");

			printf("Digite o novo nome do Autor:\n");
			scanf(" %[^\n]", livro->autor.nome);

			printf("\n");

			printf("Data de nascimento do Autor: %d/%d/%d\n", livro->data_nascimento.dia, livro->data_nascimento.mes, livro->data_nascimento.ano);

			printf("\n");

			printf("Digite a nova Data de nascimento do Autor:\n");
			scanf("%d/%d/%d", &livro->data_nascimento.dia, &livro->data_nascimento.mes, &livro->data_nascimento.ano);

			printf("\n");

			printf("Data de publicacao: %d/%d/%d\n", livro->data_escrita.dia, livro->data_escrita.mes, livro->data_escrita.ano);

			printf("\n");

			printf("Digite a nova Data de publicacao:\n");
			scanf("%d/%d/%d", &livro->data_escrita.dia, &livro->data_escrita.mes, &livro->data_escrita.ano);

			printf("\n");

			printf("Todos os campos foram editados com sucesso!\n");
		
			printf("\n");

			printf("ID: %d\n", livro->id);
			printf("Titulo: %s\n", livro->titulo);
			printf("Autor: %s\n", livro->autor.nome);
			printf("Data de Nascimento do Autor: %d/%d/%d\n", livro->data_nascimento.dia, livro->data_nascimento.mes, livro->data_nascimento.ano);
			printf("Data de Publicacao: %d/%d/%d\n", livro->data_escrita.dia, livro->data_escrita.mes, livro->data_escrita.ano);
		} 
	}

}