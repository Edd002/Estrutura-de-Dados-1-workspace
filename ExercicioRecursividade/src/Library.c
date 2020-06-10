/*
 * Library.c
 *
 *  Created on: 21 de mai de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include "Library.h"

// RECURSIVIDADE SEM CAUDA: O RETORNO DA FUNÇÃO + ALGUMA OPERAÇÃO
// RECURSIVIDADE COM CAUDA: APENAS O RETORNO DA FUNÇÃO

int calcularPotencia(int base, int expoente, int resultado) {
	if (expoente != 0)
		return calcularPotencia(base, expoente - 1, resultado * base);
	else
		return resultado;
}

void preencherVetor(int* vetor, int tamanhoVetor) {
	*vetor = rand() % 100;

	if (tamanhoVetor > 1)
		preencherVetor(++vetor, tamanhoVetor - 1);
}

int somarPosicoesVetor(int* vetor, int resultado) {
	/*
	if (vetor != '\0') {
		resultado += (*vetor);
		vetor++;
		return somarPosicoesVetor(vetor, resultado);
	}
	return resultado;
	*/
	return 0;
}
