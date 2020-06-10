/*
 ============================================================================
 Name        : AulaTypeDef.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// C: PONTEIRO -> ALOCAÇÃO DINÂMICA -> STRUCT -> LISTA

// TYPEDEF
// typedef int *intPoint;
typedef int integer;

// ENUM
// enum weekDay {sunday, monday, tuesday, wednesday, thursday, friday, saturday};
typedef enum {sunday, monday, tuesday, wednesday, thursday, friday, saturday} weekDay;

// STRUCT
struct structProducts {
	int code;
	char description[40];
	float price;
	int quantity;
};
typedef struct structProducts products;

// UNION (somente é permitido utilizar um atributo, o espaço de de memória é alocado apenas para o que está sendo usado)
union structValues {
	int valueInteger;
	float valueFloat;
};
typedef union structValues values;

int main(void) {
	setbuf(stdout, '\0');

	/*
	integer numberInteger;
	numberInteger = 0;


	weekDay day1, day2;
	day1 = sunday;
	day2 = monday;
	*/

	products product;
	product.code = 1;
	puts("Descrição do produto: ");
	gets(product.description);
	puts("Preço do produto: ");
	scanf("%f", &product.price);
	puts("Quantidade: ");
	scanf("%i", &product.quantity);


	values value;
	value.valueInteger = 10;
	value.valueFloat = 15.5; // O valueInteger é "desligado" quando o valueFloat é setado
	printf("\nValor float: %f\n", value.valueFloat);
	printf("Valor int: %i", value.valueInteger);

	return 0;
}
