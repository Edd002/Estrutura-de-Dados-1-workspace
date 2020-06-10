/*
 * Library.c
 *
 *  Created on: 23 de mai de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library.h"

dados* inserirPeloInicio(dados* lista, int codigo, char* nome) {
	// Criar espa�o de mem�ria
	dados* novo = (dados*) malloc(sizeof(dados));

	// Preencher dados
	novo->codigo = codigo;
	strcpy(novo->nome, nome);

	return novo;
}

dados* inserirPeloFim(dados* lista, int codigo, char* nome) {
	// Criar espa�o de mem�ria
	dados* novo = (dados*) malloc(sizeof(dados));

	// Preencher dados
	novo->codigo = codigo;
	strcpy(novo->nome, nome);
	novo->proximo = NULL; // Elemento novo aponta para NULL

	// Ligar � lista
	if (lista == NULL) {
		return novo;
	} else {
		dados* tmp = lista;
		while (tmp->proximo != NULL) {
			tmp = tmp->proximo;
		}
		tmp->proximo = novo;
		return lista;
	}
}

void imprimirLista(dados* lista) {
	if (lista == NULL) {
		printf("\nLista vazia.");
		return;
	}

	while (lista != NULL) {
		printf("\nRegistro atual - %p"
				"\tC�digo - %d"
				"\tNome - %s"
				"\tPr�ximo registro - %p",
				lista,
				lista->codigo,
				lista->nome,
				lista->proximo);

		lista = lista->proximo;
	}
}

// EXCLUS�O (SIMPLESMENTE ENCADEADA)
// 1.0 - Lista vazia: testa, avisa e retorna
// 		1.1 - Excluir primeiro: a lista � alterada
//		1.2 - Excluir meio: armazena o anterior e reaponta
//		1.3 - Excluir o �ltimo: vide anterior
//		1.4 - Excluir inexistente: exibe mensagem e retorna a lista recebida
dados* excluirRegistro(dados* lista, int codigo) {
	if (lista == NULL) {
		printf("\nLista vazia.");
		return lista;
	}

	dados* anterior = NULL;
	dados* atual = lista;

	while(atual != NULL) {
		if (atual->codigo == codigo) {
			if (anterior == NULL) {
				anterior = atual->proximo;
				free(atual);
				printf("\nRegistro exclu�do com sucesso.");
				return anterior;
			} else {
				anterior->proximo = atual->proximo;
				free(atual);
				return lista;
			}
		}
		anterior = atual;
		atual = atual->proximo;
	}

	printf("\nRegistro n�o encontrado.");
	return lista;
}
