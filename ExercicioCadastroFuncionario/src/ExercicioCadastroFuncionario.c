/*
 ============================================================================
 Name        : ExercicioCadastroFuncionario.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ---------------------- Quest�o 3 ----------------------
struct structDependente {
	char nome[50];
	int codigo;
	int idade;
	char parentesco;
};
typedef struct structDependente dependente;
// -------------------------------------------------------


// ---------------------- Quest�o 2 ----------------------
struct structFuncionario {
	char nome[50];
	int codigo;
	int idade;
	char cargo;
	int quantidadeDependentes;
	float salario;
	dependente* dependentes;
};
typedef struct structFuncionario funcionario;
// -------------------------------------------------------


// ---------------------- Prot�tipos ---------------------
void menu();
char* cadastrarNome(char*);
int cadastrarCodigo(char*);
int cadastrarIdade(char*);
char cadastrarParentescoDependente();
char cadastrarCargoFuncionario();
int cadastrarQuantidadeDependentesFuncionario();
float cadastrarSalarioFuncionario(char, int);
dependente* cadastrarDependentesFuncionario(int);
funcionario* cadastrarFuncionarios(int*);
void listarFuncionarios(funcionario*, int);
void listarFuncionariosPorCargo(funcionario*, int);
// -------------------------------------------------------


// ------------------------- Main ------------------------
int main(void) {
	setbuf(stdout, '\0');
	menu();
	return 0;
}
// -------------------------------------------------------


// ---------------------- Quest�o 1 ----------------------
void menu() {
	char opcao = '\0';
	funcionario* funcionarios = '\0';
	int quantidadeFuncionarios = 0;

	do {
		puts("INFORME: ");
		puts("A- Efetuar cadastro de funcion�rios");
		puts("B- Listar funcion�rios da empresa");
		puts("C- Listar funcion�rios por cargo escolhido");
		puts("D- Finalizar");
		fflush(stdin);
		scanf("%c", &opcao);

		if (opcao == 'A' || opcao == 'a') {
			funcionarios = cadastrarFuncionarios(&quantidadeFuncionarios);
			puts("");
		} else if (opcao == 'B' || opcao == 'b') {
			listarFuncionarios(funcionarios, quantidadeFuncionarios);
			puts("");
		} else if (opcao == 'C' || opcao == 'c') {
			listarFuncionariosPorCargo(funcionarios, quantidadeFuncionarios);
			puts("");
		} else if (opcao == 'D' || opcao == 'd') {
			puts("\n\nFim do programa.");
			break;
		} else {
			puts("Op��o inv�lida.\n");
		}
	} while (1);
}
// -------------------------------------------------------


// ---------------------- Quest�o 4 ----------------------
char* cadastrarNome(char entidade[11]) {
	char* nome = (char*) malloc(sizeof(char) * 50);

	printf("Informe o nome do %s: ", entidade);
	fflush(stdin);
	gets(nome);

	if (strlen(nome) == 0) {
		puts("O nome n�o pode estar em branco.\n");
		return cadastrarNome(entidade);
	}

	return nome;
}

int cadastrarCodigo(char entidade[11]) {
	return rand();
}

int cadastrarIdade(char entidade[11]) {
	int idade = 0;

	printf("Informe a idade (16 a 100 anos): ");
	fflush(stdin);
	scanf("%i", &idade);

	if (idade < 16 || idade > 100) {
		puts("A idade deve estar entre 16 e 100 anos.\n");
		return cadastrarIdade(entidade);
	}

	return idade;
}

char cadastrarParentescoDependente() {
	char parentesco = '\0';

	printf("Informe o parentesco do dependente:\nE- Enteado\nF- Filho/Filha\nT- Tutelado\n");
	fflush(stdin);
	scanf("%c", &parentesco);

	if (parentesco != 'E' && parentesco != 'e' && parentesco != 'F' && parentesco != 'f' && parentesco != 'T' && parentesco != 't') {
		puts("Parentesco informado inv�lido.\n");
		return cadastrarParentescoDependente();
	}

	return parentesco;
}

char cadastrarCargoFuncionario() {
	char cargo = '\0';

	printf("Informe o cargo do funcion�rio: \nE- Estagi�rio \nJ- N�vel J�nior \nP- N�vel Pleno \nS- N�vel S�nior \nG- N�vel Gerencial\n");
	fflush(stdin);
	scanf("%c", &cargo);

	if (cargo != 'E' && cargo != 'e' && cargo != 'J' && cargo != 'j' && cargo != 'P' && cargo != 'p' && cargo != 'S' && cargo != 's' && cargo != 'G' && cargo != 'g') {
		puts("Cargo informado inv�lido.\n");
		return cadastrarCargoFuncionario();
	}

	return cargo;
}

int cadastrarQuantidadeDependentesFuncionario() {
	int quantidadeDependentes = 0;

	printf("Informe a quantidade de dependentes (0 a 10): ");
	fflush(stdin);
	scanf("%i", &quantidadeDependentes);

	if (quantidadeDependentes < 0 || quantidadeDependentes > 10) {
		puts("A quantidade de dependentes deve ser de 0 a 10.\n");
		return cadastrarQuantidadeDependentesFuncionario();
	}

	return quantidadeDependentes;
}

float cadastrarSalarioFuncionario(char cargo, int quantidadeDependentes) {
	if (cargo == 'E' || cargo == 'e')
		return (954.00) + (15.90 * quantidadeDependentes);
	else if (cargo == 'J' || cargo == 'j')
		return (954.00 * 3) + (23.15 * quantidadeDependentes);
	else if (cargo == 'P' || cargo == 'p')
		return (954.00 * 5) + (35.72 * quantidadeDependentes);
	else if (cargo == 'S' || cargo == 's')
		return (954.00 * 7) + (49.00 * quantidadeDependentes);
	else
		return (954.00 * 9) + (68.29 * quantidadeDependentes);
}

dependente* cadastrarDependentesFuncionario(int quantidadeDependentes) {
	int i = 0;
	dependente* dependentes = (dependente*) malloc(quantidadeDependentes * sizeof(dependente));

	for (i = 0; i < quantidadeDependentes; i++) {
		printf("%i� DEPENTENTE\n", (i + 1));
		strcpy(dependentes->nome, cadastrarNome("dependente"));
		dependentes->codigo = cadastrarCodigo("dependente");
		dependentes->idade = cadastrarIdade("dependente");
		dependentes->parentesco = cadastrarParentescoDependente();

		dependentes++;
	}

	dependentes-= quantidadeDependentes;

	return dependentes;
}
// -------------------------------------------------------


// ---------------------- Quest�o 5 ----------------------
funcionario* cadastrarFuncionarios(int* quantidadeFuncionarios) {
	int i = 0;

	do {
		puts("Informe a quantidade de funcion�rios a serem cadastrados: ");
		fflush(stdin);
		scanf("%d", quantidadeFuncionarios);

		if (*quantidadeFuncionarios < 0)
			puts("A quantidade de funcion�rios n�o pode ser menor do que 0.\n");
	} while (*quantidadeFuncionarios < 0);

	funcionario* funcionarios = (funcionario*) malloc(sizeof(funcionario) * (*quantidadeFuncionarios));

	for (i = 0; i < *quantidadeFuncionarios; i++) {
		printf("%i� FUNCION�RIO\n", (i + 1));

		strcpy(funcionarios->nome, cadastrarNome("funcion�rio"));
		funcionarios->codigo = cadastrarCodigo("funcion�rio");
		funcionarios->idade = cadastrarIdade("funcion�rio");
		funcionarios->cargo = cadastrarCargoFuncionario();
		funcionarios->quantidadeDependentes = cadastrarQuantidadeDependentesFuncionario();
		funcionarios->salario = cadastrarSalarioFuncionario(funcionarios->cargo, funcionarios->quantidadeDependentes);
		if (funcionarios->quantidadeDependentes != 0)
			funcionarios->dependentes = cadastrarDependentesFuncionario(funcionarios->quantidadeDependentes);
		else
			funcionarios->dependentes = '\0';

		funcionarios++;

		puts("");
	}
	funcionarios -= (*quantidadeFuncionarios);

	return funcionarios;
}
// -------------------------------------------------------


// ---------------------- Quest�o 6 ----------------------
void listarFuncionarios(funcionario* funcionarios, int quantidadeFuncionarios) {
	int i = 0;
	int j = 0;
	for (i = 0; i < quantidadeFuncionarios; i++) {
		printf("%i� FUNCION�RIO\n", (i + 1));
		printf("Nome do funcion�rio: %s\n", funcionarios[i].nome);
		printf("C�digo do funcion�rio: %i\n", funcionarios[i].codigo);
		printf("Cargo do funcion�rio: %c\n", funcionarios[i].cargo);
		printf("Quantidade de dependentes do funcion�rio: %i\n", funcionarios[i].quantidadeDependentes);
		printf("Sal�rio do funcion�rio: %.2f\n", funcionarios[i].salario);

		for (j = 0; j < funcionarios[i].quantidadeDependentes; j++) {
			printf("\n%i� DEPENDENTE DO FUNCION�RIO\n", (j + 1));
			printf("Nome do dependente: %s\n", funcionarios[i].dependentes[j].nome);
			printf("C�digo do dependente: %i\n", funcionarios[i].dependentes[j].codigo);
			printf("Idade do dependente: %i\n", funcionarios[i].dependentes[j].idade);
			printf("Parentesco do dependente: %c\n", funcionarios[i].dependentes[j].parentesco);
		}

		puts("\n");
	}
}
// -------------------------------------------------------


// ---------------------- Quest�o 7 ----------------------
void listarFuncionariosPorCargo(funcionario* funcionarios, int quantidadeFuncionarios) {
	puts("PESQUISA POR CARGO");
	char cargoPesquisado = cadastrarCargoFuncionario();

	int contadorFuncionario = 1;
	int i = 0;
	for (i = 0; i < quantidadeFuncionarios; i++) {
		if (funcionarios[i].cargo == cargoPesquisado) {
			printf("%i� FUNCION�RIO\n", contadorFuncionario );
			printf("Nome do funcion�rio: %s\n", funcionarios[i].nome);
			printf("C�digo do funcion�rio: %i\n", funcionarios[i].codigo);
			printf("Sal�rio do funcion�rio: %.2f\n", funcionarios[i].salario);
			contadorFuncionario++;
		}

		puts("\n");
	}
}
// -------------------------------------------------------
