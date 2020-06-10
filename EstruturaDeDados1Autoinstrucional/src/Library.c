/*
 * Library.c
 *
 *  Created on: 30 de abr de 2018
 *      Author: Eduardo Augusto Lima Pereira
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include "Library.h"

// ----------------------------------------------------------------- MENU ----------------------------------------------------------------------
void menu() {
	char opcaoMenu;
	char opcaoSubmenu;
	ListaFuncionario* listaFuncionario = gerarListaFuncionario();

	do {
		opcaoMenu = '\0';
		opcaoSubmenu = '\0';

		puts("MENU: ");
		puts("A- Inserir funcion�rio");
		puts("B- Excluir dados (funcion�rio e dependentes)");
		puts("C- Alterar dados (funcion�rio e dependentes)");
		puts("D- Relat�rios");
		puts("E- Finalizar");
		fflush(stdin);
		scanf("%c", &opcaoMenu);

		if (opcaoMenu == 'A' || opcaoMenu == 'a') {
			puts("\nMENU DE INSER��O SELECIONADO\n");
			cadastrarFuncionario(listaFuncionario);
		} else if (opcaoMenu == 'B' || opcaoMenu == 'b') {
			puts("\nMENU DE EXCLUS�O SELECIONADO\n");
			do {
				puts("SUBMENU DE EXCLUS�O: ");
				puts("1- Efetuar exclus�o de funcion�rios");
				puts("2- Efetuar exclus�o de dependentes");
				puts("3- Voltar para o menu inicial");
				fflush(stdin);
				scanf("%c", &opcaoSubmenu);

				if (opcaoSubmenu == '1') {
					puts("\nSUBMENU DE EXCLUS�O DE FUNCION�RIOS SELECIONADO\n");
					excluirFuncionario(listaFuncionario);
				} else if (opcaoSubmenu == '2') {
					puts("\nSUBMENU DE EXCLUS�O DE DEPENDENTES SELECIONADO\n");
					excluirDependente(listaFuncionario);
				} else if (opcaoSubmenu == '3') {
					break;
				} else {
					puts("\nOP��O PARA SUBMENU INV�LIDA.\n");
				}
			} while(1);

			puts("\n\n");
		} else if (opcaoMenu == 'C' || opcaoMenu == 'c') {
			puts("\nMENU DE ALTERA��O SELECIONADO\n");
			do {
				puts("SUBMENU DE ALTERA��O: ");
				puts("1- Efetuar altera��o de dados de funcion�rios");
				puts("2- Efetuar altera��o de dados de dependentes");
				puts("3- Voltar para o menu inicial");
				fflush(stdin);
				scanf("%c", &opcaoSubmenu);

				if (opcaoSubmenu == '1') {
					puts("\nSUBMENU DE ALTERA��O DE FUNCION�RIOS SELECIONADO\n");
					alterarFuncionario(listaFuncionario);
				} else if (opcaoSubmenu == '2') {
					puts("\nSUBMENU DE ALTERA��O DE DEPENDENTES SELECIONADO\n");
					alterarDependente(listaFuncionario);
				} else if (opcaoSubmenu == '3') {
					break;
				} else {
					puts("\nOP��O PARA SUBMENU INV�LIDA.\n");
				}

			} while (1);
			puts("\n\n");
		} else if (opcaoMenu == 'D' || opcaoMenu == 'd') {
			puts("\nMENU DE RELAT�RIOS SELECIONADO\n");
			do {
				puts("SUBMENU DE RELAT�RIOS: ");
				puts("1- Listar todos os funcion�rios da empresa");
				puts("2- Listar funcion�rios que possuem dependentes");
				puts("3- Listar funcion�rios pela data de admiss�o");
				puts("4- Listar funcion�rios por sobrenome");
				puts("5- Listar funcion�rios por cargo escolhido");
				puts("6- Voltar para o menu inicial");
				fflush(stdin);
				scanf("%c", &opcaoSubmenu);

				if (opcaoSubmenu == '1') {
					puts("\nSUBMENU PARA LISTAR TODOS OS FUNCION�RIOS DA EMPRESA SELECIONADO\n");
					exibirFuncionarioLista(listaFuncionario);
				} else if (opcaoSubmenu == '2') {
					puts("\nSUBMENU PARA LISTAR TODOS OS FUNCION�RIOS QUE POSSUEM DEPENDENTES SELECIONADO\n");
					exibirFuncionarioComDependentesLista(listaFuncionario);
				} else if (opcaoSubmenu == '3') {
					puts("\nSUBMENU PARA LISTAR TODOS OS FUNCION�RIOS PELA DATA DE ADMISS�O SELECIONADO\n");
					exibirFuncionarioPorDataAdmissaoLista(listaFuncionario);
				} else if (opcaoSubmenu == '4') {
					puts("\nSUBMENU PARA LISTAR TODOS OS FUNCION�RIOS POR SOBRENOME SELECIONADO\n");
					exibirFuncionarioPorSobrenomeLista(listaFuncionario);
				} else if (opcaoSubmenu == '5') {
					puts("\nSUBMENU PARA LISTAR TODOS OS FUNCION�RIOS POR CARGO SELECIONADO\n");
					exibirFuncionarioPorCargoLista(listaFuncionario);
				} else if (opcaoSubmenu == '6') {
					break;
				} else {
					puts("\nOP��O PARA SUBMENU INV�LIDA.\n");
				}
			} while (1);
			puts("\n\n");
		} else if (opcaoMenu == 'E' || opcaoMenu == 'e') {
			puts("\n\nFIM DO PROGRAMA.");
			break;
		} else {
			puts("\nOP��O PARA O MENU INV�LIDA.\n");
		}
	} while(1);
}
// ---------------------------------------------------------------------------------------------------------------------------------------------


// https://www.youtube.com/watch?v=pWh_nJ66Rrk&index=0&list=PL8iN9FQ7_jt5PigiANscK2ZXqPJJ52DAT
// https://www.youtube.com/watch?v=S6rOYN-UiAA&list=PL8iN9FQ7_jt5L1c-bXpix5v0ValjahZw5


// ------------------------------------------------ MANIPULA��O DE LISTAS DE FUNCION�RIO -------------------------------------------------------
void cadastrarFuncionario(ListaFuncionario* listaFuncionario) {
	Funcionario funcionario = construirFuncionario(listaFuncionario);
	int i = 0;

	for (i = 0; i < funcionario.quantidadeDependentes; i++) {
		printf("\nCADASTRO DO %i� DEPENDENTE: \n\n", (i + 1));
		inserirDependenteLista(funcionario.listaDependente, construirDependente());
	}

	inserirFuncionarioLista(listaFuncionario, funcionario);
	exibirFuncionario(funcionario, 'C');

	if (funcionario.quantidadeDependentes > 0)
		puts("\n");
	else
		puts("\n");
}

void exibirFuncionario(Funcionario funcionario, char tipoExibicao) {
	if (tipoExibicao == 'C')
		puts("\nFUNCION�RIO CADASTRADO\n");
	else
		puts("FUNCION�RIO\n");

	printf("Nome do funcion�rio: %s", funcionario.nome);
	printf("\nMatr�cula do funcion�rio: %s", funcionario.matricula);
	printf("\nData de nascimento do funcion�rio: %s", funcionario.dataNascimento);
	printf("\nData de admiss�o do funcion�rio: %s", funcionario.dataAdmissao);
	printf("\nCargo do funcion�rio: %c", funcionario.cargo);
	printf("\nQuantidade de dependentes do funcion�rio: %i", funcionario.quantidadeDependentes);
	printf("\nSal�rio do funcion�rio: R$%.2f", funcionario.salario);

	if (funcionario.quantidadeDependentes > 0)
		exibirDependenteLista(funcionario.listaDependente);
	else
		puts("\n");
}

ListaFuncionario* gerarListaFuncionario() {
	ListaFuncionario* listaFuncionario = (ListaFuncionario*) malloc(sizeof(ListaFuncionario));
	if (listaFuncionario != '\0')
		*listaFuncionario = '\0';
	return listaFuncionario;
}

void inserirFuncionarioLista(ListaFuncionario* listaFuncionario, Funcionario funcionario) {
	ElementoFuncionario* novoFuncionario = (ElementoFuncionario*) malloc(sizeof(ElementoFuncionario));

	novoFuncionario->dadosFuncionario = funcionario;
	novoFuncionario->proximoFuncionario = (*listaFuncionario);
	novoFuncionario->anteriorFuncionario = '\0';

	if(*listaFuncionario != '\0')
		(*listaFuncionario)->anteriorFuncionario = novoFuncionario;
	*listaFuncionario = novoFuncionario;
}

void exibirFuncionarioLista(ListaFuncionario* listaFuncionario) {
	ElementoFuncionario* funcionarioConsultado = *listaFuncionario;
	int existeConsulta = 0;

	while (funcionarioConsultado != '\0') {
		exibirFuncionario(funcionarioConsultado->dadosFuncionario, 'L');
		existeConsulta = 1;
		puts("\n");
		funcionarioConsultado = funcionarioConsultado->proximoFuncionario;
	}

	if (existeConsulta == 0)
		printf("N�o existem funcion�rios cadastrados.\n\n\n");
}

void exibirFuncionarioComDependentesLista(ListaFuncionario* listaFuncionario) {
	ElementoFuncionario* funcionarioConsultado = *listaFuncionario;
	int existeConsulta = 0;

	while (funcionarioConsultado != '\0') {
		if (funcionarioConsultado->dadosFuncionario.quantidadeDependentes > 0) {
			exibirFuncionario(funcionarioConsultado->dadosFuncionario, 'L');
			existeConsulta = 1;
			puts("\n");
		}
		funcionarioConsultado = funcionarioConsultado->proximoFuncionario;
	}

	if (existeConsulta == 0)
		printf("N�o existem funcion�rios cadastrados que possuam dependentes.\n\n\n");
}

void exibirFuncionarioPorDataAdmissaoLista(ListaFuncionario* listaFuncionario) {
	ElementoFuncionario* funcionarioConsultado = *listaFuncionario;
	char* dataAdmissaoFuncionario = (char*) calloc(10, sizeof(char));
	int validadorDataAdmissaoFuncionario = 0;
	int existeConsulta = 0;

	do {
		puts("Informe a data de admiss�o para pesquisa de funcion�rios (dd/MM/yyyy): ");
		fflush(stdin);
		gets(dataAdmissaoFuncionario);

		char validadorPrimeiraBarra = '\0';
		strncpy(&validadorPrimeiraBarra, dataAdmissaoFuncionario + 2, 1);
		char validadorSegundaBarra = '\0';
		strncpy(&validadorSegundaBarra, dataAdmissaoFuncionario + 5, 1);

		if (validadorPrimeiraBarra == '/' && validadorSegundaBarra == '/' && strlen(dataAdmissaoFuncionario) == 10) {
			int diaAdmissao = 0;
			int mesAdmissao = 0;
			int anoAdmissao = 0;
			converterData(dataAdmissaoFuncionario, &diaAdmissao, &mesAdmissao, &anoAdmissao);

			if(validadorData(diaAdmissao, mesAdmissao, anoAdmissao) == 0) {
				puts("Data inv�lida.\n");
				validadorDataAdmissaoFuncionario = 0;
			} else {
				validadorDataAdmissaoFuncionario = 1;
			}
		} else {
			puts("Data inv�lida.\n");
			validadorDataAdmissaoFuncionario = 0;
		}
	} while (validadorDataAdmissaoFuncionario == 0);

	while (funcionarioConsultado != '\0') {
		if (strcmp(funcionarioConsultado->dadosFuncionario.dataAdmissao, dataAdmissaoFuncionario) == 0) {
			exibirFuncionario(funcionarioConsultado->dadosFuncionario, 'L');
			existeConsulta = 1;
			puts("\n");
		}
		funcionarioConsultado = funcionarioConsultado->proximoFuncionario;
	}

	if (existeConsulta == 0)
		printf("N�o existem funcion�rios cadastrados na data de admiss�o informada.\n\n\n");
}

void exibirFuncionarioPorSobrenomeLista(ListaFuncionario* listaFuncionario) {
	ElementoFuncionario* funcionarioConsultado = *listaFuncionario;
	char* sobrenomeFuncionario = (char*) calloc(50, sizeof(char));
	int existeConsulta = 0;

	do {
		puts("Informe o sobrenome para pesquisa de funcion�rios: ");
		fflush(stdin);
		gets(sobrenomeFuncionario);

		if (strlen(sobrenomeFuncionario) == 0)
			puts("O nome n�o pode estar em branco.\n");
	} while(strlen(sobrenomeFuncionario) == 0);

	while (funcionarioConsultado != '\0') {
		if (strcmp(capturarSobrenome(funcionarioConsultado->dadosFuncionario.nome), sobrenomeFuncionario) == 0) {
			exibirFuncionario(funcionarioConsultado->dadosFuncionario, 'L');
			existeConsulta = 1;
			puts("\n");
		}
		funcionarioConsultado = funcionarioConsultado->proximoFuncionario;
	}

	if (existeConsulta == 0)
		printf("N�o existem funcion�rios cadastrados que possuam o sobrenome informado.\n\n\n");
}

void exibirFuncionarioPorCargoLista(ListaFuncionario* listaFuncionario) {
	ElementoFuncionario* funcionarioConsultado = *listaFuncionario;
	char cargoFuncionario = '\0';
	int existeConsulta = 0;

	do {
		puts("Informe cargo para pesquisa de funcion�rios:"
				"\nE � Estagi�rio"
				"\nJ � N�vel J�nior"
				"\nP � N�vel Pleno"
				"\nS � N�vel S�nior"
				"\nG � N�vel Gerencial");
		fflush(stdin);
		scanf("%c", &cargoFuncionario);
		cargoFuncionario = toupper(cargoFuncionario);

		if (cargoFuncionario != 'E' && cargoFuncionario != 'J' && cargoFuncionario != 'P' && cargoFuncionario != 'S' && cargoFuncionario != 'G')
			puts("Cargo inv�lido.\n");
	} while (cargoFuncionario != 'E' && cargoFuncionario != 'J' && cargoFuncionario != 'P' && cargoFuncionario != 'S' && cargoFuncionario != 'G');

	while (funcionarioConsultado != '\0') {
		if (funcionarioConsultado->dadosFuncionario.cargo == cargoFuncionario) {
			exibirFuncionario(funcionarioConsultado->dadosFuncionario, 'L');
			existeConsulta = 1;
			puts("\n");
		}
		funcionarioConsultado = funcionarioConsultado->proximoFuncionario;
	}

	if (existeConsulta == 0)
		printf("N�o existem funcion�rios cadastrados que possuam este cargo.\n\n\n");
}

char* capturarSobrenome(char* nome) {
	char* sobrenome = (char*) calloc(50, sizeof(char));
	int contadorOcorenciaEspaco = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < strlen(nome); i++) {
		if (contadorOcorenciaEspaco == 1) {
			if (nome[i] != ' ') {
				sobrenome[j] = nome[i];
				j++;
			}
		} else if (contadorOcorenciaEspaco > 1) {
			break;
		}

		if (nome[i] == ' ')
			contadorOcorenciaEspaco++;
	}

	return sobrenome;
}

void excluirFuncionario(ListaFuncionario* listaFuncionario) {
	if (listaFuncionario == '\0' || (*listaFuncionario) == '\0') {
		puts("N�o h� funcion�rios cadastrados para realizar exclus�o.\n\n");
	} else {
		ElementoFuncionario* funcionarioConsultado = *listaFuncionario;
		char* matriculaFuncionario = (char*) calloc(9, sizeof(char));

		puts("Informe a matr�cula do funcion�rio que deseja excluir: ");
		fflush(stdin);
		gets(matriculaFuncionario);

		while (funcionarioConsultado != '\0' && strcmp(funcionarioConsultado->dadosFuncionario.matricula, matriculaFuncionario) != 0) {
			funcionarioConsultado = funcionarioConsultado->proximoFuncionario;
		}

		if (funcionarioConsultado == '\0') {
			puts("N�o existe funcion�rio com a matr�cula informada.\n\n");
		} else {
			if (funcionarioConsultado->anteriorFuncionario == '\0')
				*listaFuncionario = funcionarioConsultado->proximoFuncionario;
			else
				funcionarioConsultado->anteriorFuncionario->proximoFuncionario = funcionarioConsultado->proximoFuncionario;

			if (funcionarioConsultado->proximoFuncionario != '\0')
				funcionarioConsultado->proximoFuncionario->anteriorFuncionario = funcionarioConsultado->anteriorFuncionario;

			free(funcionarioConsultado);

			printf("\nO funcion�rio com a matr�cula %s foi exclu�do.\n\n\n", matriculaFuncionario);
		}
	}
}

void alterarFuncionario(ListaFuncionario* listaFuncionario) {
	if (listaFuncionario == '\0' || (*listaFuncionario) == '\0') {
		puts("N�o h� funcion�rios cadastrados para realizar altera��o.\n\n");
	} else {
		ElementoFuncionario* funcionarioConsultado = *listaFuncionario;
		char* matriculaFuncionario = (char*) calloc(9, sizeof(char));

		puts("Informe a matr�cula do funcion�rio que deseja alterar: ");
		fflush(stdin);
		gets(matriculaFuncionario);

		while (funcionarioConsultado != '\0' && strcmp(funcionarioConsultado->dadosFuncionario.matricula, matriculaFuncionario) != 0) {
			funcionarioConsultado = funcionarioConsultado->proximoFuncionario;
		}

		if (funcionarioConsultado == '\0') {
			puts("N�o existe funcion�rio com a matr�cula informada.\n\n");
		} else {
			printf("\nALTERA��O DE FUNCION�RIO - NOVOS DADOS A SEREM REINSERIDOS PARA O FUNCION�IO COM A MATR�CULA %s\n\n", matriculaFuncionario);

			// Atribuir nulo ao nome do funcion�rio em quest�o na lista para n�o contar um a mais no rec�lculo da matr�cula
			*(funcionarioConsultado->dadosFuncionario.nome) = '\0';
			funcionarioConsultado->dadosFuncionario = reconstruirFuncionario(listaFuncionario, funcionarioConsultado->dadosFuncionario);

			printf("\nO funcion�rio com a matr�cula %s foi alterado.\n\n\n", matriculaFuncionario);
		}
	}
}

// ---------------------------------------------------------------------------------------------------------------------------------------------


// ------------------------------------------------- MANIPULA��O DE LISTAS DE DEPENDENTE -------------------------------------------------------
void exibirDependente(Dependente dependente) {
	printf("Nome do dependente: %s", dependente.nome);
	printf("\nData de nascimento do dependente: %s", dependente.dataNascimento);
	printf("\nParentesco do dependente: %c", dependente.parentesco);
	printf("\nC�digo do dependente: %i", dependente.codigo);
}

ListaDependente* gerarListaDependente() {
	ListaDependente* listaDependente = (ListaDependente*) malloc(sizeof(ListaDependente));
	if (listaDependente != '\0')
		*listaDependente = '\0';
	return listaDependente;
}

void inserirDependenteLista(ListaDependente* listaDependente, Dependente dependente) {
	ElementoDependente* novoDependente = (ElementoDependente*) malloc(sizeof(ElementoDependente));

	novoDependente->dadosDependente = dependente;
	novoDependente->proximoDependente = '\0';

	if (*listaDependente == '\0') {
		*listaDependente = novoDependente;
	} else {
		ElementoDependente* auxiliarDependente = *listaDependente;
		while(auxiliarDependente->proximoDependente != '\0') {
			auxiliarDependente = auxiliarDependente->proximoDependente;
		}
		auxiliarDependente->proximoDependente = novoDependente;
	}
}

void exibirDependenteLista(ListaDependente* listaDependente) {
	ElementoDependente* dependenteConsultado = *listaDependente;
	int existeConsulta = 0;

	puts("\n\n\nDEPENDENTE(S) DO FUNCION�RIO\n");
	while (dependenteConsultado != '\0') {
		exibirDependente(dependenteConsultado->dadosDependente);
		existeConsulta = 1;
		puts("\n");
		dependenteConsultado = dependenteConsultado->proximoDependente;
	}

	if (existeConsulta == 0)
		printf("N�o existem dependentes cadastrados.\n\n\n");
}

void excluirDependente(ListaFuncionario* listaFuncionario) {
	if (listaFuncionario == '\0' || (*listaFuncionario) == '\0') {
		puts("N�o h� funcion�rios cadastrados para realizar exclus�o de dependentes.\n\n");
	} else {
		ElementoFuncionario* funcionarioConsultado = *listaFuncionario;
		char* matriculaFuncionario = (char*) calloc(9, sizeof(char));

		puts("Informe a matr�cula do funcion�rio que deseja excluir algum de seus dependentes: ");
		fflush(stdin);
		gets(matriculaFuncionario);

		while (funcionarioConsultado != '\0' && strcmp(funcionarioConsultado->dadosFuncionario.matricula, matriculaFuncionario) != 0) {
			funcionarioConsultado = funcionarioConsultado->proximoFuncionario;
		}

		if (funcionarioConsultado == '\0') {
			puts("N�o existe funcion�rio com a matr�cula informada.\n\n");
		} else {
			if (funcionarioConsultado->dadosFuncionario.quantidadeDependentes == 0) {
				puts("O funcion�rio informado n�o possui dependentes para ser removido.\n\n");
			} else {
				ElementoDependente* dependenteAnterior;
				ElementoDependente* dependenteConsultado = *(funcionarioConsultado->dadosFuncionario.listaDependente);
				int codigoDependente = 0;

				puts("Informe o c�digo do dependente que deseja excluir: ");
				fflush(stdin);
				scanf("%i", &codigoDependente);

				while (dependenteConsultado != '\0' && dependenteConsultado->dadosDependente.codigo != codigoDependente) {
					dependenteAnterior = dependenteConsultado;
					dependenteConsultado = dependenteConsultado->proximoDependente;
				}

				if (dependenteConsultado == '\0') {
					puts("N�o existe dependente cadastrado com este c�digo para este funcion�rio.\n\n");
				} else {
					if (dependenteConsultado == *(funcionarioConsultado->dadosFuncionario.listaDependente))
						*(funcionarioConsultado->dadosFuncionario.listaDependente) = dependenteConsultado->proximoDependente;
					else
						dependenteAnterior->proximoDependente = dependenteConsultado->proximoDependente;

					free(dependenteConsultado);
					funcionarioConsultado->dadosFuncionario.quantidadeDependentes--;

					printf("\nO dependente com o c�digo %i foi exclu�do.\n\n\n", codigoDependente);
				}
			}
		}
	}
}

void alterarDependente(ListaFuncionario* listaFuncionario) {
	if (listaFuncionario == '\0' || (*listaFuncionario) == '\0') {
		puts("N�o h� funcion�rios cadastrados para realizar altera��o de dependentes.\n\n");
	} else {
		ElementoFuncionario* funcionarioConsultado = *listaFuncionario;
		char* matriculaFuncionario = (char*) calloc(9, sizeof(char));

		puts("Informe a matr�cula do funcion�rio que deseja alterar algum de seus dependentes: ");
		fflush(stdin);
		gets(matriculaFuncionario);

		while (funcionarioConsultado != '\0' && strcmp(funcionarioConsultado->dadosFuncionario.matricula, matriculaFuncionario) != 0) {
			funcionarioConsultado = funcionarioConsultado->proximoFuncionario;
		}

		if (funcionarioConsultado == '\0') {
			puts("N�o existe funcion�rio com a matr�cula informada.\n\n");
		} else {
			if (funcionarioConsultado->dadosFuncionario.quantidadeDependentes == 0) {
				puts("O funcion�rio informado n�o possui dependentes para ser alterado.\n\n");
			} else {
				ElementoDependente* dependenteConsultado = *(funcionarioConsultado->dadosFuncionario.listaDependente);
				int codigoDependente = 0;

				puts("Informe o c�digo do dependente que deseja alterar: ");
				fflush(stdin);
				scanf("%i", &codigoDependente);

				while (dependenteConsultado != '\0' && dependenteConsultado->dadosDependente.codigo != codigoDependente) {
					dependenteConsultado = dependenteConsultado->proximoDependente;
				}

				if (dependenteConsultado == '\0') {
					puts("N�o existe dependente cadastrado com este c�digo para este funcion�rio.\n\n");
				} else {
					printf("\nALTERA��O DE DEPENDENTE - NOVOS DADOS A SEREM REINSERIDOS PARA O DEPENDENTE COM O C�DIGO %i DO FUNCION�RIO COM A MATR�CULA %s\n\n", codigoDependente, matriculaFuncionario);

					dependenteConsultado->dadosDependente = reconstruirDependente(dependenteConsultado->dadosDependente);

					printf("\nO dependente com o c�digo %i foi alterado.\n\n\n", codigoDependente);
				}
			}
		}
	}
}
// ---------------------------------------------------------------------------------------------------------------------------------------------


// ------------------------------------------------------ VALIDA��O DE FUNCION�RIO ------------------------------------------------------------
Funcionario construirFuncionario(ListaFuncionario* listaFuncionario) {
	Funcionario funcionario;

	strcpy(funcionario.nome, validarNomeFuncionario());
	strcpy(funcionario.matricula, validarMatriculaFuncionario(listaFuncionario, funcionario.nome));
	strcpy(funcionario.dataNascimento, validarDataNascimentoFuncionario());
	strcpy(funcionario.dataAdmissao, validarDataAdmissaoFuncionario(funcionario.dataNascimento));
	funcionario.cargo = validarCargoFuncionario();
	funcionario.quantidadeDependentes = validarQuantidadeDependentesFuncionario();
	funcionario.salario = validarSalarioFuncionario(funcionario.cargo, funcionario.quantidadeDependentes);
	funcionario.listaDependente = gerarListaDependente();

	return funcionario;
}

Funcionario reconstruirFuncionario(ListaFuncionario* listaFuncionario, Funcionario funcionario) {
	// Manter a lista de dependentes antiga e verificar se o n�mero de dependentes � maior ou menor (caso igual n�o realizar nenhuma a��o) em [validarReconstrucaoQuantidadeDependentesFuncionario]

	strcpy(funcionario.nome, validarNomeFuncionario());
	strcpy(funcionario.matricula, validarMatriculaFuncionario(listaFuncionario, funcionario.nome));
	strcpy(funcionario.dataNascimento, validarDataNascimentoFuncionario());
	strcpy(funcionario.dataAdmissao, validarDataAdmissaoFuncionario(funcionario.dataNascimento));
	funcionario.cargo = validarCargoFuncionario();
	funcionario.quantidadeDependentes = validarReconstrucaoQuantidadeDependentesFuncionario(funcionario.listaDependente, funcionario.quantidadeDependentes);
	funcionario.salario = validarSalarioFuncionario(funcionario.cargo, funcionario.quantidadeDependentes);

	return funcionario;
}

char* validarNomeFuncionario() {
	char* nomeFuncionario = (char*) calloc(50, sizeof(char));

	puts("Informe o nome do funcion�rio: ");
	fflush(stdin);
	gets(nomeFuncionario);

	if (strlen(nomeFuncionario) == 0) {
		puts("O nome n�o pode estar em branco.\n");
		return validarNomeFuncionario();
	}

	puts("----------------------------------------------------------------------------------------------------");
	realloc(nomeFuncionario, strlen(nomeFuncionario));
	return nomeFuncionario;
}

char* validarMatriculaFuncionario(ListaFuncionario* listaFuncionario, char* nomeFuncionario) {
	char* matriculaFuncionario = (char*) calloc(9, sizeof(char));
	int ascPrimeiraLetra = toupper(nomeFuncionario[0]);

	// 1� D�gito
	matriculaFuncionario[0] = toupper(nomeFuncionario[0]);

	// 2� e 3� D�gitos
	matriculaFuncionario++;
	itoa(ascPrimeiraLetra, matriculaFuncionario, 10);

	// 4� e 5� D�gitos
	matriculaFuncionario+=2;
	if (ascPrimeiraLetra - 64 >= 1 && ascPrimeiraLetra - 64 <= 9) {
		matriculaFuncionario[0] = '0';
		matriculaFuncionario++;
		itoa(ascPrimeiraLetra - 64, matriculaFuncionario, 10);
		matriculaFuncionario--;
	} else {
		itoa(ascPrimeiraLetra - 64, matriculaFuncionario, 10);
	}

	// 6� e 7� D�gitos -> Necess�rio LISTA
	matriculaFuncionario+=2;
	calularSextoSetimoDigitoMatricula(listaFuncionario, nomeFuncionario, &matriculaFuncionario[0], &matriculaFuncionario[1]);

	// 8� D�gito
	matriculaFuncionario-=4;
	int digitoVerificador = calcularDigitoVerificador(matriculaFuncionario, 0, 5, 0);
	matriculaFuncionario+=6;
	matriculaFuncionario[0] = '-';
	matriculaFuncionario[1] = digitoVerificador + '0';

	matriculaFuncionario-=7;
	//printf("\nMatr�cula: %s\n\n", matriculaFuncionario);
	return matriculaFuncionario;
}

void calularSextoSetimoDigitoMatricula(ListaFuncionario* listaFuncionario, char* nomeFuncionario, char* matriculaPosicaoSeis, char* matriculaPosicaoSete) {
	ElementoFuncionario* funcionarioConsultado = *listaFuncionario;
	int contadorOcorrenciaPrimeiraLetraMatricula = 1;

	while (funcionarioConsultado != '\0') {
		if (funcionarioConsultado->dadosFuncionario.nome[0] == nomeFuncionario[0])
			contadorOcorrenciaPrimeiraLetraMatricula++;

		funcionarioConsultado = funcionarioConsultado->proximoFuncionario;
	}

	if (contadorOcorrenciaPrimeiraLetraMatricula >= 1 && contadorOcorrenciaPrimeiraLetraMatricula <= 9) {
		*matriculaPosicaoSeis = '0';
		*matriculaPosicaoSete = contadorOcorrenciaPrimeiraLetraMatricula + '0';
	} else {
		char posicoesMatriculaSeisSete[2];
		itoa(contadorOcorrenciaPrimeiraLetraMatricula, posicoesMatriculaSeisSete, 10);
		*matriculaPosicaoSeis = posicoesMatriculaSeisSete[0];
		*matriculaPosicaoSete = posicoesMatriculaSeisSete[1];
	}
}

int calcularDigitoVerificador(char* matriculaFuncionario, int somatorioDigitoVerificador, int multiplosCinco, int i) {
	if (i != 6) {
		somatorioDigitoVerificador += ((matriculaFuncionario[i] - '0') * multiplosCinco);
		multiplosCinco+=5;
		i++;
		return calcularDigitoVerificador(matriculaFuncionario, somatorioDigitoVerificador, multiplosCinco, i);
	} else {
		return somatorioDigitoVerificador % 11 != 10 ? somatorioDigitoVerificador % 11 : 0;
	}
}

char* validarDataNascimentoFuncionario() {
	char* dataNascimentoFuncionario = (char*) calloc(10, sizeof(char));

	puts("Informe a data de nascimento do funcion�rio (dd/MM/yyyy): ");
	fflush(stdin);
	gets(dataNascimentoFuncionario);

	char validadorPrimeiraBarra = '\0';
	strncpy(&validadorPrimeiraBarra, dataNascimentoFuncionario + 2, 1);
	char validadorSegundaBarra = '\0';
	strncpy(&validadorSegundaBarra, dataNascimentoFuncionario + 5, 1);

	if (validadorPrimeiraBarra == '/' && validadorSegundaBarra == '/' && strlen(dataNascimentoFuncionario) == 10) {
		int diaNascimento = 0;
		int mesNascimento = 0;
		int anoNascimento = 0;
		converterData(dataNascimentoFuncionario, &diaNascimento, &mesNascimento, &anoNascimento);

		int diaAtual = 0;
		int mesAtual = 0;
		int anoAtual = 0;
		capturarDataSistema(&diaAtual, &mesAtual, &anoAtual);

		// Testes
		/*
		printf("Dia do nascimento: %i\n", diaNascimento);
		printf("M�s do nascimento: %i\n", mesNascimento);
		printf("Ano do nascimento: %i\n", anoNascimento);
		printf("Dia atual: %i\n", diaAtual);
		printf("M�s atual: %i\n", mesAtual);
		printf("Ano atual: %i\n", anoAtual);
		 */

		if(validadorData(diaNascimento, mesNascimento, anoNascimento) == 0 || validadorData(diaAtual, mesAtual, anoAtual) == 0) {
			puts("Data inv�lida.\n");
			return validarDataNascimentoFuncionario();
		} else {
			int diferencaDataDiasIdadeInformada = diferencaDatas(diaNascimento, mesNascimento, anoNascimento, diaAtual, mesAtual, anoAtual);
			int diferencaDataDiasIdadeMinima = diferencaDatas(diaAtual, mesAtual, anoAtual - 16, diaAtual, mesAtual, anoAtual);
			int diferencaDataDiasIdadeMaxima = diferencaDatas(diaAtual, mesAtual, anoAtual - 100, diaAtual, mesAtual, anoAtual);

			// Teste
			/*
			printf("Diferen�a entre datas em dias: %i", diferencaDataDiasIdadeInformada);
			 */

			if (diferencaDataDiasIdadeInformada < diferencaDataDiasIdadeMinima) {
				puts("\nA idade do funcion�rio deve ser pelo menos 16 anos.\n");
				return validarDataNascimentoFuncionario();
			}

			if (diferencaDataDiasIdadeInformada > diferencaDataDiasIdadeMaxima) {
				puts("\nA idade do funcion�rio deve ser menor que 100 anos.\n");
				return validarDataNascimentoFuncionario();
			}
		}
	} else {
		puts("Data inv�lida.\n");
		return validarDataNascimentoFuncionario();
	}

	puts("----------------------------------------------------------------------------------------------------");
	return dataNascimentoFuncionario;
}

char* validarDataAdmissaoFuncionario(char* dataNascimentoFuncionario) {
	char* dataAdmissaoFuncionario = (char*) calloc(10, sizeof(char));

	puts("Informe a data de admiss�o do funcion�rio (dd/MM/yyyy): ");
	fflush(stdin);
	gets(dataAdmissaoFuncionario);

	char validadorPrimeiraBarra = '\0';
	strncpy(&validadorPrimeiraBarra, dataAdmissaoFuncionario + 2, 1);
	char validadorSegundaBarra = '\0';
	strncpy(&validadorSegundaBarra, dataAdmissaoFuncionario + 5, 1);

	if (validadorPrimeiraBarra == '/' && validadorSegundaBarra == '/' && strlen(dataAdmissaoFuncionario) == 10) {
		int diaNascimento = 0;
		int mesNascimento = 0;
		int anoNascimento = 0;
		converterData(dataNascimentoFuncionario, &diaNascimento, &mesNascimento, &anoNascimento);

		int diaAdmissao = 0;
		int mesAdmissao = 0;
		int anoAdmissao = 0;
		converterData(dataAdmissaoFuncionario, &diaAdmissao, &mesAdmissao, &anoAdmissao);

		// Testes
		/*
		printf("Dia do nascimento: %i\n", diaNascimento);
		printf("M�s do nascimento: %i\n", mesNascimento);
		printf("Ano do nascimento: %i\n", anoNascimento);
		printf("Dia de Admiss�o: %i\n", diaAdmissao);
		printf("M�s de Admiss�o: %i\n", mesAdmissao);
		printf("Ano de Admiss�o: %i\n", anoAdmissao);
		 */

		if(validadorData(diaNascimento, mesNascimento, anoNascimento) == 0 || validadorData(diaAdmissao, mesAdmissao, anoAdmissao) == 0) {
			puts("Data inv�lida.\n");
			return validarDataAdmissaoFuncionario(dataNascimentoFuncionario);
		} else {
			int diferencaDataDiasIdadeInformada = diferencaDatas(diaNascimento, mesNascimento, anoNascimento, diaAdmissao, mesAdmissao, anoAdmissao);

			/*
			printf("Diferen�a entre datas em dias: %i", diferencaDataDiasIdadeInformada);
			 */

			if (diferencaDataDiasIdadeInformada < 0) {
				puts("\nA data de admiss�o n�o pode ser menor que a data de nascimento.\n");
				return validarDataAdmissaoFuncionario(dataNascimentoFuncionario);
			}
		}
	} else {
		puts("Data inv�lida.\n");
		return validarDataAdmissaoFuncionario(dataNascimentoFuncionario);
	}

	puts("----------------------------------------------------------------------------------------------------");
	return dataAdmissaoFuncionario;
}

char validarCargoFuncionario() {
	char cargoFuncionario = '\0';

	puts("Informe cargo do funcion�rio:"
			"\nE � Estagi�rio"
			"\nJ � N�vel J�nior"
			"\nP � N�vel Pleno"
			"\nS � N�vel S�nior"
			"\nG � N�vel Gerencial");
	fflush(stdin);
	scanf("%c", &cargoFuncionario);
	cargoFuncionario = toupper(cargoFuncionario);

	if (cargoFuncionario != 'E' && cargoFuncionario != 'J' && cargoFuncionario != 'P' && cargoFuncionario != 'S' && cargoFuncionario != 'G') {
		puts("\nCargo inv�lido.\n");
		return validarCargoFuncionario();
	}

	puts("----------------------------------------------------------------------------------------------------");
	return cargoFuncionario;
}

int validarQuantidadeDependentesFuncionario() {
	int quantidadeDependentesFuncionario = 0;

	puts("Informe a quantidade de dependentes do funcion�rio (0 a 10): ");
	fflush(stdin);
	scanf("%i", &quantidadeDependentesFuncionario);

	if (quantidadeDependentesFuncionario < 0 || quantidadeDependentesFuncionario > 10) {
		puts("\nA quantidade de dependentes deve estar entre 0 e 10.\n");
		return validarQuantidadeDependentesFuncionario();
	}

	puts("----------------------------------------------------------------------------------------------------");
	return quantidadeDependentesFuncionario;
}

float validarSalarioFuncionario(char cargoFuncionario, int quantidadeDependentesFuncionario) {
	if (cargoFuncionario == 'E')
		return (1 * 954.00) + (15.90 * quantidadeDependentesFuncionario);
	else if (cargoFuncionario == 'J')
		return (3 * 954.00) + (23.15 * quantidadeDependentesFuncionario);
	else if (cargoFuncionario == 'P')
		return (5 * 954.00) + (35.72 * quantidadeDependentesFuncionario);
	else if (cargoFuncionario == 'S')
		return (7 * 954.00) + (49.00 * quantidadeDependentesFuncionario);
	else if (cargoFuncionario == 'G')
		return (9 * 954.00) + (68.29 * quantidadeDependentesFuncionario);

	return 0.0;
}

int validarReconstrucaoQuantidadeDependentesFuncionario(ListaDependente* listaDependente, int quantidadeDependentesFuncionarioAntiga) {
	int quantidadeDependentesFuncionario = 0;

	puts("Informe a quantidade de dependentes do funcion�rio (0 a 10): ");
	fflush(stdin);
	scanf("%i", &quantidadeDependentesFuncionario);

	if (quantidadeDependentesFuncionario < 0 || quantidadeDependentesFuncionario > 10) {
		puts("\nA quantidade de dependentes deve estar entre 0 e 10.\n");
		return validarReconstrucaoQuantidadeDependentesFuncionario(listaDependente, quantidadeDependentesFuncionarioAntiga);
	}

	if (quantidadeDependentesFuncionario < quantidadeDependentesFuncionarioAntiga) {
		puts("\nA quantidade de dependentes n�o pode ser menor do que a anteriormente cadastrada.\n");
		return validarReconstrucaoQuantidadeDependentesFuncionario(listaDependente, quantidadeDependentesFuncionarioAntiga);
	} else if (quantidadeDependentesFuncionario > quantidadeDependentesFuncionarioAntiga) {
		puts("\nDEPENDENTES A SEREM ADICIONADOS A ESTE FUNCION�RIO");
		int i = 0;
		for (i = 0; i < (quantidadeDependentesFuncionario - quantidadeDependentesFuncionarioAntiga); i++) {
			printf("\nADICIONAR %i� DEPENDENTE: \n\n", (i + 1));
			inserirDependenteLista(listaDependente, construirDependente());
		}
	}

	return quantidadeDependentesFuncionario;
}
// ---------------------------------------------------------------------------------------------------------------------------------------------


// ------------------------------------------------------- VALIDA��O DE DEPENDENTE ------------------------------------------------------------
Dependente construirDependente() {
	Dependente dependente;

	strcpy(dependente.nome, validarNomeDependente());
	strcpy(dependente.dataNascimento, validarDataNascimentoDependente());
	dependente.parentesco = validarParentescoDependente();
	dependente.codigo = validarCodigoDependente();

	return dependente;
}

Dependente reconstruirDependente(Dependente dependente) {
	strcpy(dependente.nome, validarNomeDependente());
	strcpy(dependente.dataNascimento, validarDataNascimentoDependente());
	dependente.parentesco = validarParentescoDependente();
	dependente.codigo = validarCodigoDependente();

	return dependente;
}

char* validarNomeDependente() {
	char* nomeDependente = (char*) calloc(50, sizeof(char));

	puts("Informe o nome do dependente: ");
	fflush(stdin);
	gets(nomeDependente);

	if (strlen(nomeDependente) == 0) {
		puts("O nome n�o pode estar em branco.\n");
		return validarNomeFuncionario();
	}

	puts("----------------------------------------------------------------------------------------------------");
	realloc(nomeDependente, strlen(nomeDependente));
	return nomeDependente;
}

char* validarDataNascimentoDependente() {
	char* dataNascimentoDependente = (char*) calloc(10, sizeof(char));

	puts("Informe a data de nascimento do dependente (dd/MM/yyyy): ");
	fflush(stdin);
	gets(dataNascimentoDependente);

	char validadorPrimeiraBarra = '\0';
	strncpy(&validadorPrimeiraBarra, dataNascimentoDependente + 2, 1);
	char validadorSegundaBarra = '\0';
	strncpy(&validadorSegundaBarra, dataNascimentoDependente + 5, 1);

	if (validadorPrimeiraBarra == '/' && validadorSegundaBarra == '/' && strlen(dataNascimentoDependente) == 10) {
		int diaNascimento = 0;
		int mesNascimento = 0;
		int anoNascimento = 0;
		converterData(dataNascimentoDependente, &diaNascimento, &mesNascimento, &anoNascimento);

		int diaAtual = 0;
		int mesAtual = 0;
		int anoAtual = 0;
		capturarDataSistema(&diaAtual, &mesAtual, &anoAtual);

		// Testes
		/*
			printf("Dia do nascimento: %i\n", diaNascimento);
			printf("M�s do nascimento: %i\n", mesNascimento);
			printf("Ano do nascimento: %i\n", anoNascimento);
			printf("Dia atual: %i\n", diaAtual);
			printf("M�s atual: %i\n", mesAtual);
			printf("Ano atual: %i\n", anoAtual);
		 */

		if(validadorData(diaNascimento, mesNascimento, anoNascimento) == 0 || validadorData(diaAtual, mesAtual, anoAtual) == 0) {
			puts("Data inv�lida.\n");
			return validarDataNascimentoDependente();
		} else {
			int diferencaDataDiasIdadeInformada = diferencaDatas(diaNascimento, mesNascimento, anoNascimento, diaAtual, mesAtual, anoAtual);
			int diferencaDataDiasIdadeMaxima = diferencaDatas(diaAtual, mesAtual, anoAtual - 24, diaAtual, mesAtual, anoAtual);

			// Teste
			/*
			printf("Diferen�a entre datas em dias: %i", diferencaDataDiasIdadeInformada);
			 */

			if (diferencaDataDiasIdadeInformada < 0) {
				puts("\nA idade do dependente deve ser pelo menos 0 ano.\n");
				return validarDataNascimentoDependente();
			}

			if (diferencaDataDiasIdadeInformada > diferencaDataDiasIdadeMaxima) {
				puts("\nA idade do dependente deve ser menor que 24 anos.\n");
				return validarDataNascimentoDependente();
			}
		}
	} else {
		puts("Data inv�lida.\n");
		return validarDataNascimentoDependente();
	}

	puts("----------------------------------------------------------------------------------------------------");
	return dataNascimentoDependente;
}

char validarParentescoDependente() {
	char parentescoDependente = '\0';

	puts("Informe:"
			"\nE � Enteado"
			"\nF � Filho/Filha"
			"\nT � Tutelado");
	fflush(stdin);
	scanf("%c", &parentescoDependente);
	parentescoDependente = toupper(parentescoDependente);

	if (parentescoDependente != 'E' && parentescoDependente != 'F' && parentescoDependente != 'T') {
		puts("\nParentesco inv�lido.\n");
		return validarParentescoDependente();
	}

	puts("----------------------------------------------------------------------------------------------------");
	return parentescoDependente;
}

int validarCodigoDependente() {
	return CODIGO_DEPENDENTE;
}
// ---------------------------------------------------------------------------------------------------------------------------------------------


// ---------------------------------------------------------- VALIDA��O DE DATA ----------------------------------------------------------------
// DIFEREN�A ENTRE DATAS
int diferencaDatas(int diaData1, int mesData1, int anoData1, int diaData2, int mesData2, int anoData2) {
	int somatorio = validadorDiaAno(diaData2, mesData2, anoData2) - validadorDiaAno(diaData1, mesData1, anoData1);

	if (anoData1 != anoData2) {
		if (anoData1 < anoData2)
			somatorio += validadorBissexto(anoData1, anoData2);
		else
			somatorio -= validadorBissexto(anoData2, anoData1);
	}

	return somatorio;
}

// VALIDAR ANO BISSEXTO OU ANO NORMAL
int validadorBissexto(int anoData1, int anoData2) {
	int i;
	int diasAno = 0;

	for(i = anoData1; i < anoData2; i++) {
		diasAno += 365;
		if(validadorGregorian(i) == 1)
			diasAno += 1;
	}

	return diasAno;
}

// DIA DO ANO
int validadorDiaAno(int dia, int mes, int ano) {
	int somatorioDiaMeses[13];
	int somatorioDiasAno;

	somatorioDiaMeses[1] = 0;
	somatorioDiaMeses[2] = 31;
	somatorioDiaMeses[3] = 59;
	somatorioDiaMeses[4] = 90;
	somatorioDiaMeses[5] = 120;
	somatorioDiaMeses[6] = 151;
	somatorioDiaMeses[7] = 181;
	somatorioDiaMeses[8] = 212;
	somatorioDiaMeses[9] = 243;
	somatorioDiaMeses[10]= 273;
	somatorioDiaMeses[11]= 304;
	somatorioDiaMeses[12]= 334;
	somatorioDiasAno = somatorioDiaMeses[mes] + dia;

	if(validadorGregorian(ano) == 1 && mes > 2)
		somatorioDiasAno += 1;

	return somatorioDiasAno;
}

// VALIDAR A DATA
int validadorData(int dia, int mes, int ano) {
	int meses[13];
	if(0 < mes && mes < 13) {
		meses[1] = 32;
		meses[2] = 29;
		meses[3] = 32;
		meses[4] = 31;
		meses[5] = 32;
		meses[6] = 31;
		meses[7] = 32;
		meses[8] = 32;
		meses[9] = 31;
		meses[10]= 32;
		meses[11]= 31;
		meses[12]= 32;

		if (mes == 2 && validadorGregorian(ano) == 1)
			meses[2] = 30;

		if(0 < dia && dia < meses[mes])
			return 1;
		else
			return 0;
	} else {
		return 0;
	}
}

// VALIDA��O DO ANO NO GRAGORIAN CALENDAR
int validadorGregorian(int ano) {
	if((((ano % 400) == 0 || (ano % 100) != 0) && (ano % 4) == 0))
		return 1;
	else
		return 0;
}

// CAPTURAR DATA ATUAL DO SISTEMA %d %m %Y
void capturarDataSistema(int* diaAtual, int* mesAtual, int* anoAtual) {
	char diaAtualSistema[32];
	char mesAtualSistema[32];
	char anoAtualSistema[32];
	size_t ultimoCaracterDia;
	size_t ultimoCaracterMes;
	size_t ultimoCaracterAno;

	struct tm *ts;
	time_t timestamp = time(NULL);
	ts = localtime(&timestamp);

	ultimoCaracterDia = strftime(diaAtualSistema, 32, "%d", ts);
	diaAtualSistema[ultimoCaracterDia] = '\0';

	ultimoCaracterMes = strftime(mesAtualSistema, 32, "%m", ts);
	mesAtualSistema[ultimoCaracterMes] = '\0';

	ultimoCaracterAno = strftime(anoAtualSistema, 32, "%Y", ts);
	anoAtualSistema[ultimoCaracterAno] = '\0';

	*diaAtual = atoi(diaAtualSistema);
	*mesAtual = atoi(mesAtualSistema);
	*anoAtual = atoi(anoAtualSistema);
}

// SEPARAR STRING DE DATA EM VARI�VEIS INT
void converterData(char* data, int* dia, int* mes, int* ano) {
	//Teste
	/*
	printf("\nData: %s\n", data);
	 */

	char* charDia = (char*) calloc(2, sizeof(char));
	strncpy(charDia, data, 2);
	*dia = atoi(charDia);

	char* charMes = (char*) calloc(2, sizeof(char));
	strncpy(charMes, data + 3, 2);
	*mes = atoi(charMes);

	char* charAno = (char*) calloc(4, sizeof(char));
	strncpy(charAno, data + 6, 4);
	*ano = atoi(charAno);
}
// ---------------------------------------------------------------------------------------------------------------------------------------------
