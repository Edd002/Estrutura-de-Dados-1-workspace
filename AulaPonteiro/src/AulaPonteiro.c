/*
 ============================================================================
 Name        : AulaPonteiro.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, '\0');

	// Declarar variável
	int x = 23;

	// Declarar ponteiro (armazena o endereço do espaço de memória da variável)
	int *px;

	// Armazenar o endereço de memória de "x" em "px"
	px = &x; // int *px = &x;
	// scanf("%d", &x); = scanf("%d", px);

	// Obs.: o "&" aponta o espaço de memória da variável
	//       px -> endereço guardado no ponteiro
	//       &px -> endereço do ponteiro

	printf("\nConteúdo de x %i - Endereço de memória de x %p", x, &x);
	printf("\nConteúdo de px %p - Endereço de memória de px %p", px, &px);

	*px = 100; // *-> Guarda em x
			   // *-> Deferencia
			   // &-> Referencia

	printf("\nConteúdo de x após [*px = 100 ] %i - Endereço de memória de x %p", x, &x);

	printf("\n\nFORMAS DIRETAS E INDIRETAS");
	printf("\nForma direta - x = %i e Endereço de x = %p", x, &x);
	printf("\nForma indireta - x = %i e Endereço de x = %p", *px, px);

	printf("\n\nESTRUTURA DE REPETIÇÃO - VETOR");
	int vetor[3];
	int i = 0;
	for (i = 0; i < 3; i++) {
		printf("\n%p", &vetor[i]);
	}

	printf("\n\nMANIPULAÇÃO COM PONTEIRO");
	int vetor2[] = {5, 8, 12};
	int i2;
	int *px2 = vetor2; // Aponta para a primeira posição do vetor
	for (i2 = 0; i2 < 3; i2++) {
		printf("\n%i - %p", *px2, px2);
		px2++;
	}

	printf("\n\nMANIPULAÇÃO COM PONTEIRO 2");
	px2 = &vetor2[0]; // Aponta para a primeira posição do vetor
	for (i2 = 0; i2 < 3; i2++) {
		printf("\n%i - %p", px2[i2], &px2[i2]);
	}

	return 0;
}
