/*
 ============================================================================
 Name        : ApostilaPagina53Exercicio07.c
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
	int tamanhoString = 0;
	int i = 0;

	setbuf(stdout, NULL);

	printf("Informe a string: ");
	fflush(stdin);
	gets(string);

	for (i = 0; i < 100; i++) {
		if (string[i] != '\0')
			tamanhoString++;
		else
			break;
	}

	printf("\nTamanho da string sem uso de função: %i", tamanhoString);

	return EXIT_SUCCESS;
}
