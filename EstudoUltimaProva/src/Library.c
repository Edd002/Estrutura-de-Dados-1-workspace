/*
 * Library.c
 *
 *  Created on: 19 de jun de 2018
 *      Author: n226804875
 */

#include <stdio.h>
#include <stdlib.h>
#include "Library.h"

void menu() {
	List* list = generateList();

	insertListFinale(list);
	insertListBegin(list);
	insertListBegin(list);
	removeMiddle(list, 18467);

	showList(list);
}

List* generateList() {
	List* list = (List*) malloc(sizeof(List));
	if (list != NULL)
		*list = NULL;
	return list;
}

void insertListBegin(List* list) {
	Element newElement;
	newElement.codigo = CODIGO_RANDOMICO;

	Node* newNode = (Node*) malloc(sizeof(Node));

	newNode->previousNode = NULL;
	newNode->element = newElement;
	newNode->nextNode = (*list);

	if (*list != NULL)
		(*list)->previousNode = newNode;
	*list = newNode;
}

void insertListFinale(List* list) {
	Element newElement;
	newElement.codigo = CODIGO_RANDOMICO;

	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->element = newElement;
	newNode->nextNode = NULL;

	if (*list == NULL) {
		newNode->previousNode = NULL;
		*list = newNode;
	} else {
		Node* auxNode = (*list);
		while (auxNode->nextNode != NULL)
			auxNode = auxNode->nextNode;
		auxNode->nextNode = newNode;
		newNode->previousNode = auxNode;
	}
}

void removeMiddle(List* list, int codigoElement) {
	Node* searchNode = (Node*) malloc(sizeof(Node));
	searchNode = (*list);

	if (list == NULL || (*list) == NULL) {
		puts("Empty list for remove.\n\n");
	} else {
		while(searchNode != NULL && searchNode->element.codigo != codigoElement)
			searchNode = searchNode->nextNode;

		if (searchNode == NULL) {
			puts("No element with this code in the list.\n\n");
		} else {
			if (searchNode->previousNode == NULL)
				*list = searchNode->nextNode;
			else
				searchNode->previousNode->nextNode = searchNode->nextNode;

			if (searchNode->nextNode != NULL)
				searchNode->nextNode->previousNode = searchNode->previousNode;

			free(searchNode);

			puts("Element removed.\n");
		}
	}
}

void showList(List* list) {
	Node* node = (*list);

	while (node != NULL) {
		printf("Code: %i\n", node->element.codigo);
		node = node->nextNode;
	}
}
