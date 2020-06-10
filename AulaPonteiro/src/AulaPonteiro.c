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

	// Declarar vari�vel
	int x = 23;

	// Declarar ponteiro (armazena o endere�o do espa�o de mem�ria da vari�vel)
	int *px;

	// Armazenar o endere�o de mem�ria de "x" em "px"
	px = &x; // int *px = &x;
	// scanf("%d", &x); = scanf("%d", px);

	// Obs.: o "&" aponta o espa�o de mem�ria da vari�vel
	//       px -> endere�o guardado no ponteiro
	//       &px -> endere�o do ponteiro

	printf("\nConte�do de x %i - Endere�o de mem�ria de x %p", x, &x);
	printf("\nConte�do de px %p - Endere�o de mem�ria de px %p", px, &px);

	*px = 100; // *-> Guarda em x
			   // *-> Deferencia
			   // &-> Referencia

	printf("\nConte�do de x ap�s [*px = 100 ] %i - Endere�o de mem�ria de x %p", x, &x);

	printf("\n\nFORMAS DIRETAS E INDIRETAS");
	printf("\nForma direta - x = %i e Endere�o de x = %p", x, &x);
	printf("\nForma indireta - x = %i e Endere�o de x = %p", *px, px);

	printf("\n\nESTRUTURA DE REPETI��O - VETOR");
	int vetor[3];
	int i = 0;
	for (i = 0; i < 3; i++) {
		printf("\n%p", &vetor[i]);
	}

	printf("\n\nMANIPULA��O COM PONTEIRO");
	int vetor2[] = {5, 8, 12};
	int i2;
	int *px2 = vetor2; // Aponta para a primeira posi��o do vetor
	for (i2 = 0; i2 < 3; i2++) {
		printf("\n%i - %p", *px2, px2);
		px2++;
	}

	printf("\n\nMANIPULA��O COM PONTEIRO 2");
	px2 = &vetor2[0]; // Aponta para a primeira posi��o do vetor
	for (i2 = 0; i2 < 3; i2++) {
		printf("\n%i - %p", px2[i2], &px2[i2]);
	}

	return 0;
}
