/*
 ============================================================================
 Name        : Lista01Pratica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void menu();
int solicitarInteiro();
float solicitarReal();
void verificarTriangulo(float, float, float, char *);
void multiplica(int, int *);
void manipularVetorPonteiro();

int main(void) {
	setbuf(stdout, '\0');

	menu();

	return 0;
}

// Exercício 1
void menu() {
	char opcao = '\0';
	puts("Informe: \nA- Resultado do exercício 04\nB- Resultado do exercício 06\nC- Finalizar");
	fflush(stdin);
	scanf("%c", &opcao);

	if (opcao == 'A' || opcao == 'a') {
		puts("\nPRIMEIRIO LADO");
		float lado1 = solicitarReal();

		puts("\nSEGUNDO LADO");
		float lado2 = solicitarReal();

		puts("\nTERCEIRO LADO");
		float lado3 = solicitarReal();

		char tipoTriangulo = '\0';
		verificarTriangulo(lado1, lado2, lado3, &tipoTriangulo);

		printf("\nTipo do triângulo: %c", tipoTriangulo);

		puts("\n");
		menu();
	} else if (opcao == 'B' || opcao == 'b') {
		manipularVetorPonteiro();

		puts("\n");
		menu();
	} else if (opcao == 'C' || opcao == 'c') {
		puts("\n\nFim do programa.");
	} else {
		puts("\nEntrada inválida.\n");
		menu();
	}
}

// Exercício 2
int solicitarInteiro() {
	int inteiro = 0;

	puts("Informe um número inteiro de 0 a 10: ");
	fflush(stdin);
	scanf("%i", &inteiro);

	if (inteiro >= 0 && inteiro <= 10) {
		return inteiro;
	} else {
		puts("Entrada inválida.\n");
		return solicitarInteiro();
	}
}

// Exercício 3
float solicitarReal() {
	float real = 0.0;

	puts("Informe um número real positivo: ");
	fflush(stdin);
	scanf("%f", &real);

	if (real > 0.0) {
		return real;
	} else {
		puts("Entrada inválida.\n");
		return solicitarReal();
	}
}

// Exercício 4
void verificarTriangulo(float lado1, float lado2, float lado3, char *tipoTriangulo) {
	if ((lado1 + lado2) > lado3 && (lado1 + lado3) > lado2 && (lado2 + lado3) > lado1) {
		if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
			if (lado1 == lado2 && lado1 == lado3)
				*tipoTriangulo = 'E';
			else
				*tipoTriangulo = 'I';
		} else {
			*tipoTriangulo = 'S';
		}
	} else {
		*tipoTriangulo = 'N';
	}
}

// Exercício 5
void multiplica(int numero, int *pVet) {
	int i = 0;
	for (i = 0; i < 10; i++) {
		pVet[i] = numero * i;
	}
}

// Exercício 6
void manipularVetorPonteiro() {
	int *vetor = (int *) malloc(11 * sizeof(int));
	int numero = solicitarInteiro();
	multiplica(numero, vetor);

	puts("\nTABUADA");
	int i = 0;
	for (i = 0; i < 10; i++) {
		printf("%i * %i = %i\n", numero, i, *vetor);
		vetor++;
	}
}
