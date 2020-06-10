/*
 * Library.c
 *
 *  Created on: 25 de abr de 2018
 *      Author: n226804875
 */

#include <stdio.h>

int somar(int numero1, int numero2) {
	return numero1 + numero2;
}

int subtrair(int numero1, int numero2) {
	return numero1 - numero2;
}

int multiplicar(int numero1, int numero2) {
	return numero1 * numero2;
}

int dividir(int numero1, int numero2) {
	return numero1 / numero2;
}

int calcularResto(int numero1, int numero2) {
	return numero1 % numero2;
}

void imprimir(int numero1, int numero2, int(*pFuncao)(int, int)) {
	printf("\nResultado: %i", pFuncao(numero1, numero2));
}
