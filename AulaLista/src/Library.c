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
	// Criar espaço de memória
	dados* novo = (dados*) malloc(sizeof(dados));

	// Preencher dados
	novo->codigo = codigo;
	strcpy(novo->nome, nome);

	return novo;
}

dados* inserirPeloFim(dados* lista, int codigo, char* nome) {
	// Criar espaço de memória
	dados* novo = (dados*) malloc(sizeof(dados));

	// Preencher dados
	novo->codigo = codigo;
	strcpy(novo->nome, nome);
	novo->proximo = NULL; // Elemento novo aponta para NULL

	// Ligar à lista
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
				"\tCódigo - %d"
				"\tNome - %s"
				"\tPróximo registro - %p",
				lista,
				lista->codigo,
				lista->nome,
				lista->proximo);

		lista = lista->proximo;
	}
}

// EXCLUSÃO (SIMPLESMENTE ENCADEADA)
// 1.0 - Lista vazia: testa, avisa e retorna
// 		1.1 - Excluir primeiro: a lista é alterada
//		1.2 - Excluir meio: armazena o anterior e reaponta
//		1.3 - Excluir o último: vide anterior
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
				printf("\nRegistro excluído com sucesso.");
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

	printf("\nRegistro não encontrado.");
	return lista;
}
