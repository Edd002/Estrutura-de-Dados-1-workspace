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

// Exercício 1
void exibirMenu() {
	char opcao = '\0';

	puts("INFORME\nA para calcular o valor líquido a receber \nB para calcular novo salário \nC para sair");
	fflush(stdin);
	scanf("%c", &opcao);

	if (opcao == 'A' || opcao == 'a') {
		puts("\n--- CALCULAR VALOR LÍQUIDO A RECEBER ---\n");
		puts("NÚMERO DE DIAS TRABALHADOS PELO ENCANADOR");

		int numeroDiasTrabalhados = validarNumeroInteiro();
		float salario = 0;
		calcularValorLiquidoReceber(numeroDiasTrabalhados, &salario);

		printf("\nSalário: %fR$\n\n", salario);
		exibirMenu();
	} else if (opcao == 'B' || opcao == 'b') {
		puts("\n--- CALCULAR NOVOS SALÁRIOS ---\n");
		puts("QUANTIDADE DE SALÁRIOS A SER INFORMADOS");

		int quantidadeSalarios = 0;
		double mediaNovosSalarios = 0;
		do {
			quantidadeSalarios = validarNumeroInteiro();
			if (quantidadeSalarios != 0) {
				double *vetor = malloc(quantidadeSalarios * sizeof(double));
				mediaNovosSalarios = calcularNovosSalarios(quantidadeSalarios, vetor);
				break;
			} else {
				puts("A quantidade de salários a ser informados não pode ser 0.");
				continue;
			}
		} while (1);

		printf("%lfR$\n\n", mediaNovosSalarios);
		exibirMenu();
	} else if (opcao == 'C' || opcao == 'c') {

	} else {
		puts("Opção inválida.\n");
		exibirMenu();
	}
}

// Exercício 2
int validarNumeroInteiro() {
	float numero = 0.0;

	puts("Informe um número inteiro positivo: ");
	fflush(stdin);
	scanf("%f", &numero);

	if (numero < 0) {
		puts("O número deve ser positivo.");
		return validarNumeroInteiro();
	}

	if (numero != (int) numero) {
		puts("O número deve ser inteiro.");
		return validarNumeroInteiro();
	}

	return (int) numero;
}

// Exercício 3
float validarNumeroReal() {
	float numero = 0.0;

	puts("Informe um número real positivo: ");
	fflush(stdin);
	scanf("%f", &numero);

	if (numero < 0) {
		puts("O número deve ser positivo.");
		return validarNumeroReal();
	}

	return numero;
}

// Desconsiderar o segundo tópico na/no função/exercício 4
// Exercício 4
void calcularValorLiquidoReceber(int diasTrabalhados, float* salario) {
	*salario = (float) (diasTrabalhados * 30.0) * 0.92;
}

// Vetor criado na função exibirMenu()
// Exercício 5
double calcularNovosSalarios(int quantidadeSalarios, double* vetor) {
	puts("-- VALORES DOS SALÁRIOS --\n");
	double somatorio = 0;
	int i = 0;
	for (i = 0; i < quantidadeSalarios; i++) {
		printf("\%iº SALÁRIO\n", i + 1);
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
