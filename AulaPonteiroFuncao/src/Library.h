/*
 * Library.h
 *
 *  Created on: 25 de abr de 2018
 *      Author: n226804875
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

// Protótipos
int somar(int, int);
int subtrair(int, int);
int multiplicar(int, int);
int dividir(int, int);
int calcularResto(int, int);
void imprimir (int, int, int(*pFuncao)(int, int));

// Struct
struct structFuncoes {
	int (*somar)(int, int);
	int (*subtrair)(int, int);
	int (*multiplicar)(int, int);
	int (*dividir)(int, int);
	int (*calcularResto)(int, int);
};
typedef struct structFuncoes funcoes;

#endif /* LIBRARY_H_ */
