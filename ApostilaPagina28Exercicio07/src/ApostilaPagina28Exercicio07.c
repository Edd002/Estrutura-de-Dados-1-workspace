/*
 ============================================================================
 Name        : ApostilaPagina28Exercicio07.c
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

	float medidaQuadrado = 0;
	printf("Informe o lado do quadrado: ");
	scanf("%f", &medidaQuadrado);

	medidaQuadrado = medidaQuadrado * medidaQuadrado;
	printf("Área do quadrado informado é: %f", medidaQuadrado);

	return EXIT_SUCCESS;
}
