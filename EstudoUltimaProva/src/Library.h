/*
 * Library.h
 *
 *  Created on: 19 de jun de 2018
 *      Author: n226804875
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

typedef struct structElement {
	int codigo;
} Element;

typedef struct structNode {
	struct structNode* previousNode;
	Element element;
	struct structNode* nextNode;
} Node;

typedef Node* List;

void menu();
List* generateList();
void insertListBegin(List*);
void insertListFinale(List*);
void removeMiddle(List*, int);
void showList(List*);

#define CODIGO_RANDOMICO rand()

#endif /* LIBRARY_H_ */
