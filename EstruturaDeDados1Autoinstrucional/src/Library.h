/*
 * Library.h
 *
 *  Created on: 30 de abr de 2018
 *      Author: Eduardo Augusto Lima Pereira
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_


// STRUCTS E LISTA DE DEPENDENTE
typedef struct structDependente {
	char nome[51];
	char dataNascimento[11];
	char parentesco;
	int codigo;
} Dependente;

typedef struct structElementoDependente {
	Dependente dadosDependente;
	struct structElementoDependente* proximoDependente;
} ElementoDependente;

typedef ElementoDependente* ListaDependente;


// STRUCTS E LISTA DE FUNCIONÁRIO
typedef struct structFuncionario {
	char nome[51];
	char matricula[10];
	char dataNascimento[11];
	char dataAdmissao[11];
	char cargo;
	int quantidadeDependentes;
	float salario;
	ListaDependente* listaDependente;
} Funcionario;

typedef struct structElementoFuncionario {
	struct structElementoFuncionario* anteriorFuncionario;
	Funcionario dadosFuncionario;
	struct structElementoFuncionario* proximoFuncionario;
} ElementoFuncionario;

typedef ElementoFuncionario* ListaFuncionario;


// MENU
void menu();


// MANIPULAÇÃO DE LISTAS DE FUNCIONÁRIO
void cadastrarFuncionario(ListaFuncionario*);
void exibirFuncionario(Funcionario, char);
ListaFuncionario* gerarListaFuncionario();
void inserirFuncionarioLista(ListaFuncionario*, Funcionario);
void exibirFuncionarioLista(ListaFuncionario*);
void exibirFuncionarioComDependentesLista(ListaFuncionario*);
void exibirFuncionarioPorDataAdmissaoLista(ListaFuncionario*);
void exibirFuncionarioPorSobrenomeLista(ListaFuncionario*);
void exibirFuncionarioPorCargoLista(ListaFuncionario*);
char* capturarSobrenome(char*);
void excluirFuncionario(ListaFuncionario*);
void alterarFuncionario(ListaFuncionario*);


// MANIPULAÇÃO DE LISTAS DE DEPENDENTE
void exibirDependente(Dependente);
ListaDependente* gerarListaDependente();
void inserirDependenteLista(ListaDependente*, Dependente);
void exibirDependenteLista(ListaDependente*);
void excluirDependente(ListaFuncionario*);
void alterarDependente(ListaFuncionario*);


// ALOCAÇÃO E REALOCAÇÃO - FUNCIONÁRIO
Funcionario construirFuncionario(ListaFuncionario*);
Funcionario reconstruirFuncionario(ListaFuncionario*, Funcionario);


// VALIDAÇÃO - FUNCIONÁRIO
char* validarNomeFuncionario();
char* validarMatriculaFuncionario(ListaFuncionario*, char*);
void calularSextoSetimoDigitoMatricula(ListaFuncionario*, char*, char*, char*);
int calcularDigitoVerificador(char*, int, int, int);
char* validarDataNascimentoFuncionario();
char* validarDataAdmissaoFuncionario(char*);
char validarCargoFuncionario();
int validarQuantidadeDependentesFuncionario();
float validarSalarioFuncionario(char, int);
int validarReconstrucaoQuantidadeDependentesFuncionario(ListaDependente*, int);


// ALOCAÇÃO E REALOCAÇÃO - DEPENDENTE
Dependente construirDependente();
Dependente reconstruirDependente(Dependente);


// VALIDAÇÃO - DEPENDENTE
char* validarNomeDependente(); // String ->  char 50
char* validarDataNascimentoDependente(); // String ->  char 10
char validarParentescoDependente();
int validarCodigoDependente();


// VALIDAÇÃO - DATA
int diferencaDatas(int, int, int, int, int, int);
int validadorBissexto(int, int);
int validadorDiaAno(int, int, int);
int validadorData(int, int, int);
int validadorGregorian(int);
void capturarDataSistema(int*, int*, int*);
void converterData(char*, int*, int*, int*);


// MACROS
#define CODIGO_DEPENDENTE rand()


#endif /* LIBRARY_H_ */
