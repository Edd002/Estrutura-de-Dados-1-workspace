/*
 ============================================================================
 Name        : Exercicio02.c
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

	float salario = 0;
	printf("Informe o salário: ");
	scanf("%f", &salario);

	salario = salario > 5000 ? salario * 1.1 : salario * 1.15;
	printf("Salário com aumento: %.2f", salario);

	return EXIT_SUCCESS;
}
