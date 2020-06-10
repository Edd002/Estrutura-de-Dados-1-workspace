/*
 * Library.h
 *
 *  Created on: 11 de jun de 2018
 *      Author: n226804875
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

typedef struct structItem {
	int codigo;
} Item;

typedef struct structElementoItem {
	struct structElementoItem* anteriorItem;
	Item dadosItem;
	struct structElementoItem* proximoItem;
} ElementoItem;

typedef ElementoItem* ListaItem;

void menu();
ListaItem* gerarListaItem();
void inserirItemListaInicio(ListaItem*);
void inserirItemListaFim(ListaItem*);
void removerItem(ListaItem*);
void exibirItemLista(ListaItem*);
int efetuarSomatorioRecursivo(int, int);
int efetuarSomatorioRecursivoCauda(int, int);

#define NUMERO_RANDOMICO rand() % 1000

#endif /* LIBRARY_H_ */
