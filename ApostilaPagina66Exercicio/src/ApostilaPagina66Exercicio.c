/*
 ============================================================================
 Name        : ApostilaPagina66Exercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// Aloca��o de vetor din�mica: malloc ou calloc
	setbuf(stdout, '\0');

	int *vetor;
	float tamanhoVetor = 0.0;
	int tamanhoVetorValidado = 0;
	int i = 0;
	int somatorioValoresVetor = 0;

	do {
		printf("Informe o tamanho do vetor: ");
		fflush(stdin);
		scanf("%f", &tamanhoVetor);

		if (tamanhoVetor != (int) tamanhoVetor) {
			puts("\nO n�mero informado deve ser inteiro.\n");
			continue;
		}

		if (tamanhoVetor < 1) {
			puts("\nO tamanho do vetor deve ser positivo.\n");
			continue;
		}

		tamanhoVetorValidado = (int) tamanhoVetor;
		break;
	} while (1);

	// Aloca��o de espa�os de mem�ria do tipo inteiro para formar o vetor: calloc e malloc retornam um ponteiro com um tamanho X determinado pelo(s) par�metro(s)
	vetor = (int *) calloc(tamanhoVetorValidado, sizeof(int)); // Ponteiro apontando para primeira posi��o &vetor[0]

	// &vetor[i] -> endere�o de mem�ria da posi��o do vetor
	// vetor[i] -> conte�do da posi��o do vetor

	for (i = 0; i < tamanhoVetorValidado; i++) {
		printf("\nInforme o %i� valor: ", i + 1);
		fflush(stdin);
		scanf("%i", &vetor[i]);
	}

	for (i = 0; i < tamanhoVetorValidado; i++) {
		if (i % 2 == 0)
			vetor[i] = vetor[i] * 2;
		else
			vetor[i] = vetor[i] / 2;
	}

	puts("\nNOVO VETOR");
	for (i = 0; i < tamanhoVetorValidado; i++) {
		printf("\nValor da posic�o %i: %i", i + 1, vetor[i]);
		somatorioValoresVetor += vetor[i];
	}

	printf("\nSOMA DOS VALORES DO VETOR: %i", somatorioValoresVetor);

	// Caso o ponteiro n�o esteja apontando para o in�cio, apont�-lo antes do free()
	free(vetor); // &vetor[0]
	puts("\n\nFim do programa.");

	return 0;
}
