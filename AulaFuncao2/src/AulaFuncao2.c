/*
 ============================================================================
 Name        : AulaFuncao2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void funcaoPonteiro(int *, int);
void funcaoPonteiroVetorIndexacao(int *, int, int *);
void funcaoPonteiroVetorAritmeticaPonteiro(int *, int, int *);

int main(void) {
	setbuf(stdout, '\0');

	int numero1 = 10;
	int numero2 = 20;

	int vetor[] = {15, 25, 65, 78};
	int soma;

	funcaoPonteiro(&numero1, numero2);
	printf("Número1: %i \nNúmero2: %i", numero1, numero2);

	// Parâmetro por referência (ponteiro): INDEXAÇÃO ou ARITMÉTICA DE PONTEIRO
	funcaoPonteiroVetorIndexacao(vetor /*&vetor[0]*/, 4, &soma);
	funcaoPonteiroVetorAritmeticaPonteiro(vetor /*&vetor[0]*/, 4, &soma);

	printf("\n\nSoma: %i\nVetor: { %i, %i, %i, %i }", soma, vetor[0], vetor[1], vetor[2], vetor[3]);

	return 0;
}

void funcaoPonteiro(int *numero1, int numero2) {
	*numero1 = 50;
	numero2 = 40;
}

void funcaoPonteiroVetorIndexacao(int *pVetor, int tamanho, int *pSoma) {
	int i = 0;
	*pSoma = 0;

	for (i = 0; i < tamanho; i++) {
		*pSoma += pVetor[i];
	}
}

void funcaoPonteiroVetorAritmeticaPonteiro(int *pVetor, int tamanho, int *pSoma) {
	int i = 0;
	*pSoma = 0;

	for (i = 0; i < tamanho; i++) {
		*pSoma += *pVetor;
		pVetor++;
	}
}
