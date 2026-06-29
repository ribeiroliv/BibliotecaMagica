/*Essa função auxilia na busca dos livros por id*/
livroMagico * buscaId(struct livroMagico **biblioteca, int id) {
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
void mostrarLivro(struct livroMagico **biblioteca, int id) {
	struct livroMagico *livro = buscaId(biblioteca, id);

	if(livro != NULL) {
		printf("ID: %d\n", livro->id);
		printf("Titulo: %s\n", livro->titulo);
		printf("Autor: %s\n", livro->autor.nome);
		printf("Data: %d/%d/%d\n", livro->data_escrita.dia, livro->data_escrita.mes, livro->data_escrita.ano);	
	} else {
		printf("Livro nao encontrado!\n");
	}
}

/*Essa função imprime a lista de todos os livros da biblioteca e seus respectivos IDs*/
void listarTitulos(struct livroMagico **biblioteca) {
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