/*
 ============================================================================
 Name        : AulaPonteiroFuncao.c
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

	// EXEMPLO 1
	/*
	int (*pFuncao)(int, int);

	pFuncao = somar;
	printf("\nResultado: %i", pFuncao(15, 98));

	pFuncao = subtrair;
	printf("\nResultado: %i", pFuncao(15, 98));
	*/

	// EXEMPLO 2
	/*
	imprimir(15, 98, subtrair);
	imprimir(15, somar(38, 60), somar);
	*/

	// EXEMPLO 3
	/*
	int i = 0;
	int (*pFuncao[])(int, int) = {somar, subtrair};

	for (i = 0; i < 2; i++) {
		imprimir(15, 98, pFuncao[i]);
	}
	*/

	// EXEMPLO 4
	funcoes funcao = {.somar = somar, .subtrair = subtrair, .multiplicar = multiplicar, .dividir = dividir, .calcularResto = calcularResto};
	printf("Soma: %i", funcao.somar(15, 98));
	printf("\nSubtração: %i", funcao.subtrair(15, 98));
	printf("\nMultiplicação: %i", funcao.multiplicar(15, 98));
	printf("\nDivisão: %i", funcao.dividir(15, 98));
	printf("\nResto: %i", funcao.calcularResto(15, 98));

	return 0;
}
