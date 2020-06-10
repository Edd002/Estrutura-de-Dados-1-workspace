/*
 ============================================================================
 Name        : ApostilaPagina28Exercicio04.c
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

	int numero1 = 0;
	int numero2 = 0;

	printf("Informe o valor para o primeiro número: ");
	scanf("%i", &numero1);

	printf("\nInforme o valor para o primeiro número: ");
	scanf("%i", &numero2);

	printf("\nResto da divisão: %i - %i = %i", numero1, numero2, numero1 - numero2);

	return EXIT_SUCCESS;
}
