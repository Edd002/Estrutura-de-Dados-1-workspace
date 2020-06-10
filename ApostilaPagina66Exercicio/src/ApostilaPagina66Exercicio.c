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
	// Alocação de vetor dinâmica: malloc ou calloc
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
			puts("\nO número informado deve ser inteiro.\n");
			continue;
		}

		if (tamanhoVetor < 1) {
			puts("\nO tamanho do vetor deve ser positivo.\n");
			continue;
		}

		tamanhoVetorValidado = (int) tamanhoVetor;
		break;
	} while (1);

	// Alocação de espaços de memória do tipo inteiro para formar o vetor: calloc e malloc retornam um ponteiro com um tamanho X determinado pelo(s) parâmetro(s)
	vetor = (int *) calloc(tamanhoVetorValidado, sizeof(int)); // Ponteiro apontando para primeira posição &vetor[0]

	// &vetor[i] -> endereço de memória da posição do vetor
	// vetor[i] -> conteúdo da posição do vetor

	for (i = 0; i < tamanhoVetorValidado; i++) {
		printf("\nInforme o %iº valor: ", i + 1);
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
		printf("\nValor da posicão %i: %i", i + 1, vetor[i]);
		somatorioValoresVetor += vetor[i];
	}

	printf("\nSOMA DOS VALORES DO VETOR: %i", somatorioValoresVetor);

	// Caso o ponteiro não esteja apontando para o início, apontá-lo antes do free()
	free(vetor); // &vetor[0]
	puts("\n\nFim do programa.");

	return 0;
}
