/*
 ============================================================================
 Name        : AlocacaoDinamica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// syzeof(estrutura) - retorna o tamanho, em bytes, de uma estrutura qualquer (vari�vel ou tipo)
	// malloc(tamanho em bytes) - aloca espa�o de mem�ria
	// free(ponteiro) - libera o espa�o de mem�ria
	// calloc(quantidade de espa�os reservados, tamanho em bytes) - aloca blocos de mem�ria limpando o que estava alocado
	// realloc(ponteiro, tamanho em bytes) - realoca espa�o de mem�ria
	setbuf(stdout, '\0');

	printf("\n%d", (int) sizeof(float));

	return 0;
}
