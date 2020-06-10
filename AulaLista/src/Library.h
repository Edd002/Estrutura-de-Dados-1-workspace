/*
 * Library.h
 *
 *  Created on: 23 de mai de 2018
 *      Author: n226804875
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

typedef struct structDados {
	char nome[30];
	int codigo;
	struct structDados* proximo;
} dados;

dados* inserirPeloInicio(dados*, int, char*);
dados* inserirPeloFim(dados* lista, int, char*);
void imprimirLista(dados*);
dados* excluirRegistro(dados*, int);

#endif /* LIBRARY_H_ */
