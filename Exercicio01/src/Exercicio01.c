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

	//printf("\nMENSAGEM MESCLADA \nVari�vel Float: %f \nVari�vel Char: %c", variavelFloat, variavelCaractere);

	printf("\nInforme um valor para a vari�vel: ");
	scanf("%f", &variavelFloat);

	printf("\nSa�da variavelFloat: %f \nSa�da vari�velCaractere: %c", variavelFloat, variavelCaractere);

	return EXIT_SUCCESS;
}
