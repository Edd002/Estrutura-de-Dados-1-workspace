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
	fflush(stdin);

	int vetor[] = {15, 96, 78};
	int *pVetor;
	pVetor = vetor; // pVetor = &vetor[0];

	printf("\nPrimeiro valor: %i"
			"\nEndereço de memória: %p"
			"\nEndereço de memória do ponteiro: %p",
			*pVetor, pVetor, &pVetor);

	puts("\n");
	pVetor++; // "andar" com o ponteiro

	printf("\nSegundo valor: %i"
			"\nEndereço de memória: %p"
			"\nEndereço de memória do ponteiro: %p",
			*pVetor, pVetor, &pVetor);

	puts("\n");
	(*pVetor)++; // somar mais 1 no valor

	printf("\nTerceiro valor: %i"
			"\nEndereço de memória: %p"
			"\nEndereço de memória do ponteiro: %p",
			*pVetor, pVetor, &pVetor);

	puts("\n");
	//*(pVetor++); // "andar" um espaço com o ponteiro e perder o valor

	printf("\nQuarto valor: %i"
			"\nEndereço de memória: %p"
			"\nEndereço de memória do ponteiro: %p",
			*pVetor, pVetor, &pVetor);

	return 0;
}
