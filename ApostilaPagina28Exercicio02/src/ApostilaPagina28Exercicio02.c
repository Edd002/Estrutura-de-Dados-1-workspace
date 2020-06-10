/*
 ============================================================================
 Name        : ApostilaPagina28Exercicio02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int variavel = 0;

	printf("Informe a variável: ");
	scanf("%i", &variavel);

	printf("Variável: %i\nAntecessor: %i\nSucessor: %i", variavel, variavel - 1, variavel + 1);

	return EXIT_SUCCESS;
}
