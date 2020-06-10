/*
 ============================================================================
 Name        : ExercicioPagina85.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Quest�o 2
struct structProdutos {
	int codigo;
	int quantidade;
	double preco;
	char descricao[40];
};
typedef struct structProdutos produtos;

void showMenu();
int solicitarQuantidadeTotalProdutos(produtos*);
void cadastrarProdutos(int, produtos*);
void exibirProdutosEmFaltaEstoque(int, produtos*);
void exibirProdutosEmEstoque(int, produtos*);

int main(void) {
	setbuf(stdout, '\0');
	showMenu();
	return 0;
}

// Quest�o 1
void showMenu() {
	char opcao = '\0';
	int numeroTotalProdutos = 0;
	produtos produtosAlocados;

	do {

		puts("INFORME: ");
		puts("A para criar estrutura para preenchimento");
		puts("B para preencher dados");
		puts("C para exibir produtos com estoque zerado");
		puts("D para exibir produtos em estoque");
		puts("E para finalizar");
		fflush(stdin);
		scanf("%c", &opcao);

		if (opcao == 'A' || opcao == 'a') {
			numeroTotalProdutos = solicitarQuantidadeTotalProdutos(&produtosAlocados);
		} else if (opcao == 'B' || opcao == 'b') {
			cadastrarProdutos(numeroTotalProdutos, &produtosAlocados);
		} else if (opcao == 'C' || opcao == 'c') {
			exibirProdutosEmFaltaEstoque(numeroTotalProdutos, &produtosAlocados);
		} else if (opcao == 'D' || opcao == 'd') {
			exibirProdutosEmEstoque(numeroTotalProdutos, &produtosAlocados);
		} else if (opcao == 'E' || opcao == 'e') {
			break;
		} else {
			puts("Op��o inv�lida.\n");
		}
	} while (1);
}

// Quest�o 3
int solicitarQuantidadeTotalProdutos(produtos* produtosAlocados) {
	int numeroTotalProdutos = 0;

	puts("Informe o n�mero total de produtos: ");
	fflush(stdin);
	scanf("%i", &numeroTotalProdutos);

	if (numeroTotalProdutos <= 0) {
		puts("O n�mero total de produtos deve ser um n�mero positivo.\n");
		return solicitarQuantidadeTotalProdutos(produtosAlocados);
	} else {
		produtosAlocados = (produtos *) malloc(numeroTotalProdutos * sizeof(produtos));
		return numeroTotalProdutos;
	}
}

// Quest�o 4
void cadastrarProdutos(int numeroTotalProdutos, produtos* produtosAlocados) {
	int i = 0;
	for (i = 0; i < numeroTotalProdutos; i++) {
		do {
			puts("Informe o c�digo do produto: ");
			fflush(stdin);
			scanf("%i", &produtosAlocados[i].codigo);

			if (produtosAlocados[i].codigo < 0 || produtosAlocados[i].codigo > 50)
				puts("O c�digo deve estar entre 0 e 50.\n");
		} while (produtosAlocados[i].codigo < 0 || produtosAlocados[i].codigo > 50);

		do {
			puts("Informe a quantidade: ");
			fflush(stdin);
			scanf("%i", &produtosAlocados[i].quantidade);

			if (produtosAlocados[i].quantidade < 0)
				puts("A quantidade n�o pode ser negativa.\n");
		} while (produtosAlocados[i].quantidade < 0);

		do {
			puts("Informe o pre�o: ");
			fflush(stdin);
			scanf("%lf", &produtosAlocados[i].preco);

			if (produtosAlocados[i].preco < 0)
				puts("O preco n�o pode ser negativo.\n");
		} while (produtosAlocados[i].preco < 0);

		do {
			puts("Informe a descri��o: ");
			fflush(stdin);
			gets(produtosAlocados[i].descricao);

			if (strlen(produtosAlocados[i].descricao) == 0)
				puts("A descri��o n�o pode ser vazia.\n");
		} while (strlen(produtosAlocados[i].descricao) == 0);

		puts("");
	}
}

// Quest�o 5
void exibirProdutosEmFaltaEstoque(int numeroTotalProdutos, produtos* produtosAlocados) {
	int i = 0;

	puts("PRODUTOS EM FALTA");
	for (i = 0; i < numeroTotalProdutos; i++) {
		if (produtosAlocados->quantidade == 0)
			printf("%s\n", produtosAlocados->descricao);
		produtosAlocados++;
	}

	produtosAlocados -= numeroTotalProdutos;
	puts("");
}

// Quest�o 6
void exibirProdutosEmEstoque(int numeroTotalProdutos, produtos* produtosAlocados) {
	int i = 0;

	puts("PRODUTOS EM ESTOQUE");
	for (i = 0; i < numeroTotalProdutos; i++) {
		if (produtosAlocados[i].quantidade != 0)
			printf("%s\n", produtosAlocados[i].descricao);
	}

	puts("");
}
