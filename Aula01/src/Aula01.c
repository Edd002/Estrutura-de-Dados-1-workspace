/*
 ============================================================================
 Name        : Aula01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int variavelI = 15;
	//float variavelD = 0;

	puts("!!!Hello World!!!");
	printf("\nProjeto de Testes");

	printf("\nO valor da variável inteira é: %i", variavelI);
	//printf("\nO valor da variável decimal é: %d", variavelD);

	printf("\nO valor da variável = %i sendo que %i / 2 = %.2f", variavelI, variavelI, (float) variavelI / 2);

	return EXIT_SUCCESS;
}
