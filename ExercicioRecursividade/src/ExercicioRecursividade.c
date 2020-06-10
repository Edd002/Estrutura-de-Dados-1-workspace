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

	puts("informe a opção: ");
	fflush(stdin);
	scanf("%c", &opcao);

	if (opcao == '1') {
		// FUNÇÃO QUE CALCULE UMA POTÊNCIA
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
		// FUNÇÃO PARA PREENCHER UM VETOR COM N POSIÇÕES (rand())
		int tamanhoVetor = 0;
		puts("Informe o tamanho do vetor: ");
		fflush(stdin);
		scanf("%i", &tamanhoVetor);

		int* vetor = (int*) calloc(tamanhoVetor, sizeof(int));
		preencherVetor(vetor, tamanhoVetor);

		// FUNÇÃO QUE SOME TODAS AS POSIÇÕES DE UM VETOR
		printf("\nSoma de posições: %i", somarPosicoesVetor(vetor, 0));
	}

	puts("\n\nFIM DO PROGRAMA");

	return EXIT_SUCCESS;
}
