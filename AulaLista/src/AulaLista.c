/*
 ============================================================================
 Name        : AulaLista.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library.h"

int main(void) {
	setbuf(stdout, NULL);
	dados* lista = NULL;

	// INSERIR PELO INÍCIO
	// lista = inserirPeloInicio(lista, 0, "NOME0");
	// lista = inserirPeloInicio(lista, 1, "NOME1");

	lista = inserirPeloFim(lista, 0, "NOME0");
	lista = inserirPeloFim(lista, 1, "NOME1");
	lista = inserirPeloFim(lista, 2, "NOME2");

	printf("Antes de excluir: ");
	imprimirLista(lista);
	excluirRegistro(lista, 0);

	printf("\n\nDepois de excluir: ");
	imprimirLista(lista);

	return EXIT_SUCCESS;
}
