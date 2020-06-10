/*
 ============================================================================
 Name        : ApostilaPagina53Exercicio02.c
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
	// STRCAT(string1, string2) -> CONCATENAR STRINGS

	setbuf(stdout, NULL);

	char string1[50];
	char string2[50];

	printf("Informe a primeira string: ");
	fflush(stdin);
	gets(string1);

	printf("Informe a segunda string: ");
	fflush(stdin);
	gets(string2);

	// Concatenar
	printf("Concatenação: %s", strcat(strcat(string1, " "), string2));

	return EXIT_SUCCESS;
}
