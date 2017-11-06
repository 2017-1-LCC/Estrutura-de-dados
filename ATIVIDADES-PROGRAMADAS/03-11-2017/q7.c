/*
DISCIPLINA: ESTRUTURA DE DADOS
PROFESSOR: JOSÉ HONORATO FERREIRA NUNES
DATA DA AULA : 03/11/2017
DATA DA ENTREGA : 09/11/2017
ENVIAR P/ : honoratonunes@gmail.com

Utilizando estrutura, fazer um programa em C que permita a entrada de
nome, endereço e telefone de 5 pessoas e os imprima em ordem
alfabética.
*/

#include <stdio.h>
#include <locale.h>

typedef struct {
    char name[20];
    char address[50];
    char phone[9];
} People;

void insertPeople(People *peopleList, int tam);
void orderPeople(People *peopleList, int tam);

main() {
    setlocale(LC_ALL,"portuguese_Brazil");

    People list[4];
    insertPeople(list, 4);
    orderPeople(list, 4);
}

void insertPeople(People *peopleList, int tam) {
    int num;
    for(num = 0; num < tam; num++) {
        printf("### Inserindo informações da %dº pessoa ### \n",num+1);
        printf("Digite o nome da pessoa: ");
        scanf("%s",peopleList[num].name);
        printf("Digite o endereço da pessoa: ");
        scanf("%s",peopleList[num].address);
        printf("Digite o telefone da pessoa: ");
        scanf("%d",peopleList[num].phone);
    }
}

void orderPeople(People *peopleList, int tam) {
    People temp;
    int lin, col, num;
	   
    for(lin = 0; lin < tam; lin++) {	
    	for(col = lin; col < tam; col++) {s
    		if(strcmp(peopleList[lin].name, peopleList[col].name) > 0) {
				temp = peopleList[lin];
				peopleList[lin] = peopleList[col];
				peopleList[col] = temp;
			}
		}
	}
    
    for(num = 0; num < tam; num++) {
		printf("%s \n",peopleList[num].name);
    }
}
