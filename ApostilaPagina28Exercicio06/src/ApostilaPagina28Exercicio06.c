/*
 ============================================================================
 Name        : ApostilaPagina28Exercicio06.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	float salarioFuncionario = 0;

	printf("Informe o sal�rio da funcion�rio: ");
	scanf("%f", &salarioFuncionario);

	salarioFuncionario *= 1.25;

	printf("O sal�rio com aumento de 25%% �: R$%.2f", salarioFuncionario);

	return EXIT_SUCCESS;
}
