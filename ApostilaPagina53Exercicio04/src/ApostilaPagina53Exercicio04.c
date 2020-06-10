/*
 ============================================================================
 Name        : ApostilaPagina53Exercicio04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	// STRCPY(stringDetino, stringOrigem) -> SUBSTITUIR/SOBRESCREVER UMA STRING POR OUTRA

	char string1[50];
	char string2[50];

	setbuf(stdout, NULL);

	printf("Informe a primeira string: ");
	fflush(stdin);
	gets(string1);

	printf("Informe a segunda string: ");
	fflush(stdin);
	gets(string2);

	printf("SAÍDA: %s", strcpy(string1, string2));

	return EXIT_SUCCESS;
}
