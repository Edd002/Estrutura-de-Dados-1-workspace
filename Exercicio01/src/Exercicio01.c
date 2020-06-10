/*
 ============================================================================
 Name        : Exercicio01.c
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

	float variavelFloat = 0.0;
	char variavelCaractere = 'L';

	//printf("\nMENSAGEM MESCLADA \nVariável Float: %f \nVariável Char: %c", variavelFloat, variavelCaractere);

	printf("\nInforme um valor para a variável: ");
	scanf("%f", &variavelFloat);

	printf("\nSaída variavelFloat: %f \nSaída variávelCaractere: %c", variavelFloat, variavelCaractere);

	return EXIT_SUCCESS;
}
