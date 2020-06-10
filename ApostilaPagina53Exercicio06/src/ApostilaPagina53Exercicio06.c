/*
 ============================================================================
 Name        : ApostilaPagina53Exercicio06.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	// STRLEN(string) -> RETORNA A QUANTIDADE DE CARACTERES ANTES DO '\0' (TAMANHO DA STRING)

	char string[100];

	setbuf(stdout, NULL);

	printf("Informe a string: ");
	fflush(stdin);
	gets(string);

	printf("\nTamanho da string com a função strlen(string): %i", (int) strlen(string));

	return EXIT_SUCCESS;
}
