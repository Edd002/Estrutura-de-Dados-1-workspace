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
	// syzeof(estrutura) - retorna o tamanho, em bytes, de uma estrutura qualquer (variável ou tipo)
	// malloc(tamanho em bytes) - aloca espaço de memória
	// free(ponteiro) - libera o espaço de memória
	// calloc(quantidade de espaços reservados, tamanho em bytes) - aloca blocos de memória limpando o que estava alocado
	// realloc(ponteiro, tamanho em bytes) - realoca espaço de memória
	setbuf(stdout, '\0');

	printf("\n%d", (int) sizeof(float));

	return 0;
}
