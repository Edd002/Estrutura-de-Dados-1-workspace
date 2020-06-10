/*
 ============================================================================
 Name        : ExercicioApostilaPagina44.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	setbuf(stdout, NULL);
	// n = 1
	// A- [n + (n - 1)] / n^2
	// B- n^3 / 10^(n-1)
	// C- n / [3 * (n * 2)]
	// n++

	char opcao = '0';
	int n = 1;
	int quantidadeTermosValidado = 0;
	float quantidadeTermosNaoValidado = 0;

	// Validar opção para série
	for(;;) {
		do {
			printf("INFORME A OPÇÃO PARA SÉRIE: ");
			printf("\nA - Série A - [n + (n - 1)] / n^2");
			printf("\nB - Série B - n^3 / 10^(n-1)");
			printf("\nC - Série C - n / [3 * (n * 2)]");
			printf("\nD - Sair\n");

			fflush(stdin);
			scanf("%c", &opcao);

			if (opcao < 65 || opcao > 68) {
				printf("\nSeleciona uma das opções listadas para série.\n");
				continue;
			}

			break;
		} while (1);

		// Sair
		if (opcao == 'D')
			break;

		// Validar quantidade de termos da série
		do {
			printf("\nInforme a quantidade de termos a ser calculado: ");
			scanf("%f", &quantidadeTermosNaoValidado);

			if(quantidadeTermosNaoValidado - (int) quantidadeTermosNaoValidado == 0) {
				if (quantidadeTermosNaoValidado > 0) {
					quantidadeTermosValidado = (int) quantidadeTermosNaoValidado;
				} else {
					printf("\nA quantidade de termos deve ser um número positivo.");
					continue;
				}
			} else {
				printf("\nA quantidade de termos deve ser um número inteiro.");
				continue;
			}

			break;
		} while (1);

		// Cálculo das séries
		n = 1;
		if (opcao == 'A') {
			while (n <= quantidadeTermosValidado) {
				printf("\n");
				printf("%i + %i", n, n - 1);
				printf("\n______\n");
				printf("  %i", (int) pow(n, 2));
				printf("\n");
				n++;
			}
		} else if (opcao == 'B') {
			do {
				printf("\n");
				printf("%i", (int) pow(n, 3));
				printf("\n______\n");
				printf("%i", (int) pow(10, n - 1));
				printf("\n");
				n++;
			} while (n <= quantidadeTermosValidado);
		} else if (opcao == 'C') {
			for (n = 1; n <= quantidadeTermosValidado; n++) {
				printf("\n");
				printf("%i", n);
				printf("\n______\n");
				printf("%i x %i", 3, n * 2);
				printf("\n");
			}
		}

		printf("\n\n");
	}

	printf("\n\nFim do programa.");

	return EXIT_SUCCESS;
}
