/*
 * Library.c
 *
 *  Created on: 2 de mai de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "Library.h"

// Quest�o 5
funcionario* gerarVetorEstruturaFuncionario() {
	return (funcionario*) malloc(CONSTANTE * sizeof(funcionario));
}

// Quest�o 6
char* preencherNomeFuncionario() {
	char* nome = (char*) malloc(50 * sizeof(char));

	puts("Informe o nome do funcion�rio: ");
	fflush(stdin);
	gets(nome);

	if (strlen(nome) == 0) {
		puts("O nome n�o pode ser em branco.\n");
		return preencherNomeFuncionario();
	}

	return nome;
}

// Quest�o 7
float preencherSalarioFuncionario() {
	float salario = 0.0;

	puts("Informe o sal�rio do funcion�rio: ");
	fflush(stdin);
	scanf("%f", &salario);

	if (salario <= 0.0) {
		puts("O sal�rio deve ser positivo.\n");
		return preencherSalarioFuncionario();
	}

	return salario;
}

// Quest�o 8
char preencherConvenio() {
	char convenio = '\0';

	puts("Informe S para SIM ou N para N�O: ");
	fflush(stdin);
	scanf("%c", &convenio);

	if (convenio != 'S' && convenio != 'N') {
		puts("Entrada para conv�nio inv�lida.\n");
		return preencherConvenio();
	}

	return convenio;
}

// Quest�o 9
void preencherFuncionarios(funcionario* funcionarios) {
	int contadorFuncionarios = 0;
	do {
		printf("%i� FUNCION�RIO\n", (contadorFuncionarios + 1));

		strcpy(funcionarios->nome, preencherNomeFuncionario());
		funcionarios->salario = preencherSalarioFuncionario();
		funcionarios->convenio = preencherConvenio();

		funcionarios->salario = NOVO_SALARIO(funcionarios->salario);
		funcionarios->salario = DEBITAR_SALARIO_CONVENIO(funcionarios->salario, funcionarios->convenio);

		funcionarios++;
		contadorFuncionarios++;
		puts("");
	} while (contadorFuncionarios < CONSTANTE);

	funcionarios -= CONSTANTE;
}

// Quest�o 12
void exibirFuncionarios(funcionario* funcionarios) {
	float maiorSalario = FLT_MIN;
	float mediaSalarialFuncionarios = 0.0;
	char* nomeFuncionarioMaiorSalario = (char*) malloc(50 * sizeof(char));
	int i = 0;

	puts("DADOS DOS FUNCION�RIOS");
	for (i = 0; i < CONSTANTE; i++) {
		printf("\n%i� FUNCION�RIO\n", (i + 1));

		printf("Nome: %s\n", funcionarios->nome);
		printf("Novo Sal�rio: %.2f\n", funcionarios->salario);
		printf("Conv�nio: %c\n", funcionarios->convenio);

		mediaSalarialFuncionarios += funcionarios->salario;

		if(funcionarios->salario > maiorSalario) {
			maiorSalario = funcionarios->salario;
			strcpy(nomeFuncionarioMaiorSalario, funcionarios->nome);
		}

		funcionarios++;
	}

	mediaSalarialFuncionarios /= CONSTANTE;

	printf("\nM�dia salarial dos funcion�rios: %f\n", mediaSalarialFuncionarios);
	printf("\nNome do funcion�rio com maior sal�rio: %s\n", nomeFuncionarioMaiorSalario);

	funcionarios -= CONSTANTE;
}
