/*
 ============================================================================
 Name        : ListaExercicios05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

void exibirMenu();
int validarNumeroInteiro();
float validarNumeroReal();
void calcularValorLiquidoReceber(int, float*);
double calcularNovosSalarios(int, double*);

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, '\0');

	exibirMenu();

	return 0;
}

// Exerc�cio 1
void exibirMenu() {
	char opcao = '\0';

	puts("INFORME\nA para calcular o valor l�quido a receber \nB para calcular novo sal�rio \nC para sair");
	fflush(stdin);
	scanf("%c", &opcao);

	if (opcao == 'A' || opcao == 'a') {
		puts("\n--- CALCULAR VALOR L�QUIDO A RECEBER ---\n");
		puts("N�MERO DE DIAS TRABALHADOS PELO ENCANADOR");

		int numeroDiasTrabalhados = validarNumeroInteiro();
		float salario = 0;
		calcularValorLiquidoReceber(numeroDiasTrabalhados, &salario);

		printf("\nSal�rio: %fR$\n\n", salario);
		exibirMenu();
	} else if (opcao == 'B' || opcao == 'b') {
		puts("\n--- CALCULAR NOVOS SAL�RIOS ---\n");
		puts("QUANTIDADE DE SAL�RIOS A SER INFORMADOS");

		int quantidadeSalarios = 0;
		double mediaNovosSalarios = 0;
		do {
			quantidadeSalarios = validarNumeroInteiro();
			if (quantidadeSalarios != 0) {
				double *vetor = malloc(quantidadeSalarios * sizeof(double));
				mediaNovosSalarios = calcularNovosSalarios(quantidadeSalarios, vetor);
				break;
			} else {
				puts("A quantidade de sal�rios a ser informados n�o pode ser 0.");
				continue;
			}
		} while (1);

		printf("%lfR$\n\n", mediaNovosSalarios);
		exibirMenu();
	} else if (opcao == 'C' || opcao == 'c') {

	} else {
		puts("Op��o inv�lida.\n");
		exibirMenu();
	}
}

// Exerc�cio 2
int validarNumeroInteiro() {
	float numero = 0.0;

	puts("Informe um n�mero inteiro positivo: ");
	fflush(stdin);
	scanf("%f", &numero);

	if (numero < 0) {
		puts("O n�mero deve ser positivo.");
		return validarNumeroInteiro();
	}

	if (numero != (int) numero) {
		puts("O n�mero deve ser inteiro.");
		return validarNumeroInteiro();
	}

	return (int) numero;
}

// Exerc�cio 3
float validarNumeroReal() {
	float numero = 0.0;

	puts("Informe um n�mero real positivo: ");
	fflush(stdin);
	scanf("%f", &numero);

	if (numero < 0) {
		puts("O n�mero deve ser positivo.");
		return validarNumeroReal();
	}

	return numero;
}

// Desconsiderar o segundo t�pico na/no fun��o/exerc�cio 4
// Exerc�cio 4
void calcularValorLiquidoReceber(int diasTrabalhados, float* salario) {
	*salario = (float) (diasTrabalhados * 30.0) * 0.92;
}

// Vetor criado na fun��o exibirMenu()
// Exerc�cio 5
double calcularNovosSalarios(int quantidadeSalarios, double* vetor) {
	puts("-- VALORES DOS SAL�RIOS --\n");
	double somatorio = 0;
	int i = 0;
	for (i = 0; i < quantidadeSalarios; i++) {
		printf("\%i� SAL�RIO\n", i + 1);
		*vetor = validarNumeroReal();

		if (*vetor <= 1500.00)
			*vetor *= 1.15;
		else if (*vetor > 1500.00 && *vetor <= 5000.00)
			*vetor *= 1.10;
		else if (*vetor > 5000.00 && *vetor <= 15000.00)
			*vetor *= 1.05;

		somatorio += *vetor;
		vetor++;
	}

	vetor -= quantidadeSalarios;
	free(vetor);

	return somatorio / quantidadeSalarios;
}
