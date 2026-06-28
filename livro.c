/*Essa função auxilia na busca dos livros por id*/
livroMagico * buscaId(struct livroMagico **biblioteca, int id) {
	int i;
	for(i = 0; i < 100; i++) {
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