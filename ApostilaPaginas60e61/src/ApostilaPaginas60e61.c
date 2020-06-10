/*
 ============================================================================
 Name        : ApostilaPaginas60e61.c
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

	/*
	 * 1) É uma variável responsável por armazenar o endereço de memória de outra variável.
	 *
	 * 2) b) char *ponteiro; -> Verdadeiro
	 * 	  d) *ponteiro; -> Verdadeiro
	 *
	 * 3) double *ponteiro -> c) A variável apontada por ponteiro.
	 *
	 * 4) scanf("%d", *px); -> Verdadeiro
	 * 	  Porque "*" aponta o conteúdo da variável apontada.
	 *
	 * 5)
	 *
	 * 6) a) numero == &ponteiroNumero -> Falso
	 * 	  b) numero == *ponteiroNumero -> Verdadeiro
	 * 	  c) ponteiroNumero == *numero -> Falso
	 *	  d) ponteiroNumero == &numero -> Verdadeiro
	 *
	 * 7) pj = &j;
	 *
	 * 8) a) p == &i -> Verdadeiro
	 * 	  b) *p - *q -> -2
	 * 	  c) **&p = *p -> 3
	 *
	 *  */

	return 0;
}
