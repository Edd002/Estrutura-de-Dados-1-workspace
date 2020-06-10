/*
 ============================================================================
 Name        : ApostilaPagina53Exercicio03.c
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
	// STRCMP(string1, string) -> ORDENAR STRINGS DE ACORDO COM A TABELA ASC (ALFABÉTICAMENTE)
	//
	// -1 string1 primeiro
	// 0 string1 = string2
	// 1 string2 primeiro

	setbuf(stdout, NULL);
	int stringCount = 1;

	printf("Informe quantas strings deseja informar: ");
	fflush(stdin);
	scanf("%i", &stringCount);

	int i = 0;
	int j = 0;
	char strings[stringCount][100];
	char stringStorage[100];

	if (stringCount > 0) {
		for (i = 0; i < stringCount; i++) {
			printf("Informe a %iª string: ", i+1);
			fflush(stdin);
			gets(strings[i]);
		}

		printf("\n\nORDEM INFORMADA");
		for (i = 0; i < stringCount; i++)
			printf("\n%iª: %s ", i + 1, strings[i]);

		fflush(stdin);
		printf("\n\nORDEM ALFABÉTICA\n");
		for(i = 0; i <= stringCount; i++) {
			for(j = i + 1; j <= stringCount; j++) {
				if(strcmp(strings[i], strings[j]) > 0){
				strcpy(stringStorage, strings[i]);
				strcpy(strings[i], strings[j]);
				strcpy(strings[j], stringStorage);
				}
			}
		}

		for(i = 0; i <= stringCount; i++) {
			if (i != 0)
				printf("%iª: %s\n", i, strings[i]);
		}
	}

	printf("\n\nFim do programa.");

	return EXIT_SUCCESS;
}
