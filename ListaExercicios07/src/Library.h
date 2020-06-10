/*
 * Library.h
 *
 *  Created on: 2 de mai de 2018
 *      Author: n226804875
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

// Quest�o 3
struct structFuncionario {
	char nome[50];
	float salario;
	char convenio;
};

// Quest�o 4
typedef struct structFuncionario funcionario;

// Prot�tipos
char* preencherNomeFuncionario();
float preencherSalarioFuncionario();
char preencherConvenio();
void preencherFuncionarios(funcionario*);
void exibirFuncionarios(funcionario*);


// Quest�o 1
#define CONSTANTE 10

// Quest�o 2
#define MACRO(valor1, valor2) (valor1) * (valor2)

// Quest�o 10
#define NOVO_SALARIO(salarioAntigo) salarioAntigo <= 2000.00 ? (salarioAntigo * 1.15) : (salarioAntigo <= 7500.00 ? (salarioAntigo * 1.1) : (salarioAntigo * 1.05))

// Quest�o 11
#define DEBITAR_SALARIO_CONVENIO(salario, possuiConvenio) possuiConvenio == 'S' ? (salario - 52.90) : salario

#endif /* LIBRARY_H_ */
