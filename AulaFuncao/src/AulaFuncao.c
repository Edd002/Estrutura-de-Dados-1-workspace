/*
 ============================================================================
 Name        : AulaFuncao.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Prot�tipos - exercutar as fun��es na ordem desejada
int somarNumeros(int numero1, int numero2);
float subtrair(float, float);
void mensagem();

int main(void) {
	setbuf(stdout, '\0');

	mensagem();
	printf("\nSoma de dois n�meros: %i\n", somarNumeros(5, 56));

	return 0;
}

int somarNumeros(int numero1, int numero2) {
	return numero1 + numero2;
}

float subtrair(float numero1, float numero2) {
	return numero1 - numero2;
}

void mensagem() {
	puts("IN�CIO DO PROGRAMA.\n");
}
