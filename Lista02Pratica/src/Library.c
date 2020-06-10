/*
 * Library.c
 *
 *  Created on: 11 de jun de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Library.h"

void menu() {
	char opcao = NULL;
	ListaItem* listaItem = gerarListaItem();

	do {
		puts("INFORME:\n"
				"A � Execu��o do exerc�cio 04\n"
				"B � Execu��o do exerc�cio 05\n"
				"C � Execu��o do exerc�cio 06\n"
				"D � Execu��o do exerc�cio 07\n"
				"E � Execu��o do exerc�cio 08\n"
				"F � Execu��o do exerc�cio 09\n"
				"G � Finalizar programa.");
		fflush(stdin);
		scanf("%c", &opcao);
		opcao = toupper(opcao);

		switch (opcao) {
		case 'A':
			puts("OP��O A\n");
			inserirItemListaInicio(listaItem);
			continue;
		case 'B':
			puts("OP��O B\n");
			inserirItemListaFim(listaItem);
			continue;
		case 'C':
			puts("OP��O C\n");
			removerItem(listaItem);
			continue;
		case 'D':
			puts("OP��O D\n");
			exibirItemLista(listaItem);
			continue;
		case 'E':
			puts("OP��O E\n");

			int n = 0;
			puts("Informe o a quantidade de vezes que ocorrer� o somat�rio (n): ");
			scanf("%i", &n);

			printf("\nSomat�rio: %i\n\n", efetuarSomatorioRecursivo(n, 0));
			continue;
		case 'F':
			puts("OP��O F\n");

			int nCauda = 0;
			puts("Informe o a quantidade de vezes que ocorrer� o somat�rio (n): ");
			scanf("%i", &nCauda);

			printf("\nSomat�rio: %i\n\n", efetuarSomatorioRecursivoCauda(nCauda, 0));
			continue;
		case 'G':
			puts("\n\nFIM DO PROGRAMA");
			break;
		default:
			puts("Op��o inv�lida.\n");
			break;
		}
	} while(opcao != 'G');
}

// FUNC - IN�CIO / DEP - FINAL

ListaItem* gerarListaItem() {
	ListaItem* listaItem = (ListaItem*) malloc(sizeof(ListaItem));
	if (listaItem != NULL)
		*listaItem = NULL;
	return listaItem;
}

void inserirItemListaInicio(ListaItem* listaItem) {
	Item item;
	item.codigo = NUMERO_RANDOMICO;

	ElementoItem* novoItem = (ElementoItem*) malloc(sizeof(ElementoItem));

	novoItem->dadosItem = item;
	novoItem->proximoItem = (*listaItem);
	novoItem->anteriorItem = NULL;

	if (*listaItem != NULL)
		(*listaItem)->anteriorItem = novoItem;
	*listaItem = novoItem;
}

void inserirItemListaFim(ListaItem* listaItem) {
	Item item;
	item.codigo = NUMERO_RANDOMICO;

	ElementoItem* novoItem = (ElementoItem*) malloc(sizeof(ElementoItem));
	novoItem->dadosItem = item;
	novoItem->proximoItem = NULL;

	if (*listaItem == NULL) {
		novoItem->anteriorItem = NULL;
		*listaItem = novoItem;
	} else {
		ElementoItem* aux = *listaItem;
		while (aux->proximoItem != NULL)
			aux = aux->proximoItem;
		aux->proximoItem = novoItem;
		novoItem->anteriorItem = aux;
	}
}

void removerItem(ListaItem* listaItem) {
	if (listaItem == NULL || (*listaItem) == NULL) {
		puts("N�o h� itens para na lista para executar uma remo��o.\n\n");
	} else {
		ElementoItem* elementoItemConsultado = *listaItem;
		int codigoItem = 0;

		puts("Informe o c�digo para remo��o: ");
		fflush(stdin);
		scanf("%i", &codigoItem);

		while (elementoItemConsultado != NULL  && elementoItemConsultado->dadosItem.codigo != codigoItem) {
			elementoItemConsultado = elementoItemConsultado->proximoItem;
		}

		if(elementoItemConsultado == NULL) {
			puts("O c�digo informado para remo��o n�o est� na lista.\n\n");
		} else {
			if (elementoItemConsultado->anteriorItem == NULL)
				*listaItem = elementoItemConsultado->proximoItem;
			else
				elementoItemConsultado->anteriorItem->proximoItem = elementoItemConsultado->proximoItem;

			if (elementoItemConsultado->proximoItem != NULL)
				elementoItemConsultado->proximoItem->anteriorItem = elementoItemConsultado->anteriorItem;

			free(elementoItemConsultado);

			printf("\nO item com o c�digo %i for removidoda lista.\n\n\n", codigoItem);
		}
	}
}

void exibirItemLista(ListaItem* listaItem) {
	ElementoItem* elementoItemConsultado = *listaItem;
	int existeConsulta = 0;

	while (elementoItemConsultado != NULL) {
		printf("\nC�digo do item: %i", elementoItemConsultado->dadosItem.codigo);
		existeConsulta = 1;
		elementoItemConsultado = elementoItemConsultado->proximoItem;
	}

	if (existeConsulta == 0) {
		puts("N�o existe itens na lista para exibi��o.\n\n");
		return;
	}

	puts("\n\n");
}

int efetuarSomatorioRecursivo(int n, int resultado) {
	if (n != 0)
		resultado = efetuarSomatorioRecursivo(n - 1, resultado) + n;

	return resultado;
}

int efetuarSomatorioRecursivoCauda(int n, int resultado) {
	if (n != 0)
		return efetuarSomatorioRecursivo(n - 1, resultado + n);

	return resultado;
}
