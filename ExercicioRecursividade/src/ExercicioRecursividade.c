/*
 ============================================================================
 Name        : ExercicioRecursividade.c
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
	setbuf(stdout, NULL);

	char opcao = '2';

	puts("informe a op��o: ");
	fflush(stdin);
	scanf("%c", &opcao);

	if (opcao == '1') {
		// FUN��O QUE CALCULE UMA POT�NCIA
		int base = 0;
		int expoente = 0;

		puts("Informe a base: ");
		fflush(stdin);
		scanf("%i", &base);

		puts("Informe o expoente: ");
		fflush(stdin);
		scanf("%i", &expoente);

		printf("\nResultado: %i", calcularPotencia(base, expoente, 1));
	} else if (opcao == '2') {
		// FUN��O PARA PREENCHER UM VETOR COM N POSI��ES (rand())
		int tamanhoVetor = 0;
		puts("Informe o tamanho do vetor: ");
		fflush(stdin);
		scanf("%i", &tamanhoVetor);

		int* vetor = (int*) calloc(tamanhoVetor, sizeof(int));
		preencherVetor(vetor, tamanhoVetor);

		// FUN��O QUE SOME TODAS AS POSI��ES DE UM VETOR
		printf("\nSoma de posi��es: %i", somarPosicoesVetor(vetor, 0));
	}

	puts("\n\nFIM DO PROGRAMA");

	return EXIT_SUCCESS;
}
