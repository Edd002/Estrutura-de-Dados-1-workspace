/*
 ============================================================================
 Name        : ApostilaPagina53Exercicio01.c
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
	// GETS() -> RECEBER STRING

	// NULL = '\0' -> Finalizador de String em vetor de char
	setbuf(stdout, NULL);

	char frase1[30];
	char frase2[30];

	printf("Infomre a primeira String: ");
	fflush(stdin);
	gets(frase1);

	printf("Informe a segunda String: ");
	fflush(stdin);
	gets(frase2);

	printf("\nFrase 1: %s", frase1);
	printf("\nFrase 2: %s", frase2);

	return EXIT_SUCCESS;
}
