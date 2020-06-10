/*
 ============================================================================
 Name        : AulaDiretiva.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Library.h"

int main(void) {
	setbuf(stdout, '\0');

	int resultado = function(15, 12);
	printf("Função: %i\n", resultado);

	printf("\n%s e %d", NOME, TAM);

	printf("\n%i", MAX(15, 12));
	printf("\n%i", SQUARE_POW(3+6));

	return 0;
}
