/*
 ============================================================================
 Name        : ApostilaPagina53Exercicio05.c
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
	// STRCHR(string, char) -> RETORNA A PRIMEIRA OCORRÊNCIA DO CARACTER NA STRING

	char string[50];
	char caracter = ' ';
	int i = 0;

	setbuf(stdout, NULL);

	printf("Informe a string: ");
	fflush(stdin);
	gets(string);

	printf("Informe o caracter: ");
	fflush(stdin);
	scanf("%c", &caracter);

	for (i = 0; i < strlen(string); i++) {
		if (string[i] == caracter)
			string[i] = '*';
	}

	printf("\nString nova: %s", string);

	puts("\n\nFim do programa.");

	return EXIT_SUCCESS;
}
