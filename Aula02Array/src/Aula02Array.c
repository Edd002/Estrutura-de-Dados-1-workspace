/*
 ============================================================================
 Name        : Aula02Array.c
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

	int i;
	int j;

	printf("VETOR");
	// Vetor
	int 	vetInt[10];
	//char	letrasVetor[] = {'A', 'B', 'C'};
	//float 	salarios[5];

	// O contador não pode ser declarado na estrutura do C
	for (i = 0; i < 10; i++) {
		printf("\nDigite o %dº valor: ", i + 1);
		fflush(stdin);
		scanf("%i", &vetInt[i]);
	}


	printf("MATRIZ\n");
	// Matriz
	int 	matInt[2][5];
	//char 	letrasMatriz[][3] = {'5', 'R', 'i', 'p', 'ç', 't'};

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 5; j++) {
			matInt[i][j] = rand() % 1000;
			printf("\t%d", matInt[i][j]);
		}
		printf("\n");
	}

	printf("\n\nFim do programa.");

	return EXIT_SUCCESS;
}
