/*
 ============================================================================
 Name        : ListaExercicios07.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library.h"

int main(void) {
	setbuf(stdout, '\0');

	funcionario* funcionarios = gerarVetorEstruturaFuncionario();
	preencherFuncionarios(funcionarios);
	exibirFuncionarios(funcionarios);

	puts("\n\nFIM DO PROGRAMA.");

	return 0;
}
