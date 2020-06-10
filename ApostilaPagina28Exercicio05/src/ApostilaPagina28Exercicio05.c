/*
 ============================================================================
 Name        : ApostilaPagina28Exercicio05.c
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

	int quantidadePaoFrances = 0;
	int quantidadeBroa = 0;

	float totalArrecadadoPaoFrances = 0;
	float totalArrecadadoBroa = 0;
	float totalGeral = 0;
	float valorGuardarPoupanca = 0;

	printf("Informe a quantidade de pães franceses: ");
	scanf("%i", &quantidadePaoFrances);

	printf("Informe a quantiade de broas: ");
	scanf("%i", &quantidadeBroa);

	totalArrecadadoPaoFrances = quantidadePaoFrances * 0.62;
	totalArrecadadoBroa = quantidadeBroa * 2.9;
	totalGeral = totalArrecadadoPaoFrances + totalArrecadadoBroa;
	valorGuardarPoupanca = totalGeral * 0.3;

	printf("\nTotal arrecadado com pães franceses: R$%.2f", totalArrecadadoPaoFrances);
	printf("\nTotal arrecadado com broas: R$%.2f", totalArrecadadoBroa);
	printf("\nTotal arrecadado geral: R$%.2f", totalGeral);
	printf("\nValor a ser guardado na poupança: R$%.2f", valorGuardarPoupanca);

	return EXIT_SUCCESS;
}
