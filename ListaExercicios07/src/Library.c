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

// Questão 5
funcionario* gerarVetorEstruturaFuncionario() {
	return (funcionario*) malloc(CONSTANTE * sizeof(funcionario));
}

// Questão 6
char* preencherNomeFuncionario() {
	char* nome = (char*) malloc(50 * sizeof(char));

	puts("Informe o nome do funcionário: ");
	fflush(stdin);
	gets(nome);

	if (strlen(nome) == 0) {
		puts("O nome não pode ser em branco.\n");
		return preencherNomeFuncionario();
	}

	return nome;
}

// Questão 7
float preencherSalarioFuncionario() {
	float salario = 0.0;

	puts("Informe o salário do funcionário: ");
	fflush(stdin);
	scanf("%f", &salario);

	if (salario <= 0.0) {
		puts("O salário deve ser positivo.\n");
		return preencherSalarioFuncionario();
	}

	return salario;
}

// Questão 8
char preencherConvenio() {
	char convenio = '\0';

	puts("Informe S para SIM ou N para NÃO: ");
	fflush(stdin);
	scanf("%c", &convenio);

	if (convenio != 'S' && convenio != 'N') {
		puts("Entrada para convênio inválida.\n");
		return preencherConvenio();
	}

	return convenio;
}

// Questão 9
void preencherFuncionarios(funcionario* funcionarios) {
	int contadorFuncionarios = 0;
	do {
		printf("%iº FUNCIONÁRIO\n", (contadorFuncionarios + 1));

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

// Questão 12
void exibirFuncionarios(funcionario* funcionarios) {
	float maiorSalario = FLT_MIN;
	float mediaSalarialFuncionarios = 0.0;
	char* nomeFuncionarioMaiorSalario = (char*) malloc(50 * sizeof(char));
	int i = 0;

	puts("DADOS DOS FUNCIONÁRIOS");
	for (i = 0; i < CONSTANTE; i++) {
		printf("\n%iº FUNCIONÁRIO\n", (i + 1));

		printf("Nome: %s\n", funcionarios->nome);
		printf("Novo Salário: %.2f\n", funcionarios->salario);
		printf("Convênio: %c\n", funcionarios->convenio);

		mediaSalarialFuncionarios += funcionarios->salario;

		if(funcionarios->salario > maiorSalario) {
			maiorSalario = funcionarios->salario;
			strcpy(nomeFuncionarioMaiorSalario, funcionarios->nome);
		}

		funcionarios++;
	}

	mediaSalarialFuncionarios /= CONSTANTE;

	printf("\nMédia salarial dos funcionários: %f\n", mediaSalarialFuncionarios);
	printf("\nNome do funcionário com maior salário: %s\n", nomeFuncionarioMaiorSalario);

	funcionarios -= CONSTANTE;
}
