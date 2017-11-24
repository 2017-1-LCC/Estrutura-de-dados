/*
ATIVIDADE

struct objeto {
	int qntElements;
	int matricula[m];
	float nota[m];
}

0 - Sair - ok
1 - Inserir no final da lista - ok
2 - Determinar o número de nós de uma lista - ok
3 - Localizar o nó que contém uma determinada matricula -
4 - Mostrar o valor de um determinado nó -
5 - Excluir um K_ésimo nó da lista - ok
6 - Mostrar a maior nota da lista e o número da matricula do aluno -
7 - inserir um novo nó após o K_Èsimo nó da lista. - ok
8 - Ordenar a lista -
9 - Gerar uma subcadeia ( sublista ) , somente com alunos a provados ( nota > 7 ) e mostrar na tela.
10 - mostrar todos os elementos da lista.

*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 0
#define false 1
#define TAM_LIST 10

// DECLARAR STRUCT
typedef struct {
	int qtdElements;
	char matricula[TAM_LIST];
    float nota[TAM_LIST];
}nameStruct;


// DECLARA AS FUNCOES
// PASSAR STRUCT PARA AS FUNCOES
void startList(nameStruct *object);
void insertElementOnFinal(nameStruct *object);
void removeElementOnFinal(nameStruct *object);
void showAllElements(nameStruct *object);
void orderList(nameStruct *object);
void acessElementOnList(nameStruct *object);
void countQtdElementsOnList(nameStruct *object);
int menu();
void exit();


//INICIA O CODE
main() {
	setlocale(LC_ALL,"portuguese_Brazil");
	menu();
}


// FUNCOES COMPLETAS
void startList(nameStruct *object) {
	object->qtdElements = 0;
}

// 01 - Inserir no final da lista
void insertElementOnFinal(nameStruct *object) {

    system("clear");

	char atributo;

	if(object->qtdElements > TAM_LIST - 1) {
		printf("ERROR 489 - LIST IS FULL!");
	} else {
		printf("Digite o novo elemento da lista: ");
		scanf(" %c",&atributo);
		object->atributo[object->qtdElements] = atributo;
		object->qtdElements++;
		printf("elemento [ --> %c] inserido com sucesso! \n",atributo);
	}
}

// 02 - Determinar o número de nós de uma lista
void countQtdElementsOnList(nameStruct *object) {
    printf("Elementos na lista: %d",object->qtdElements);
}


// 03 - Localizar o nó que contém uma determinada matricula
void findMatriculaOnList(nameStruct *object) {

    system("clear");

    int tam, matricula;

    printf("Informe a matricula: ");
    scanf("%d",&matricula);

    if(object->qtdElements == 0) {
        printf("ERROR 586 - LIST IS EMPTY");
    } else {
        printf("| ---- EXIBINDO ELEMENTOS DA LISTA ---- | \n");
        for(tam = 0; tam < object->qtdElements; tam++) {
            if(matricula == object->matricula[tam]) {
                printf("Matricula %d encontrada com a nota %f",object->matricula[tam], object->nota[tam]);
            }

        }
    }
}

//04 - Mostrar o valor de um determinado nó
void acessElementOnList(nameStruct *object) {

    system("clear");

	int position;
	printf("Informe a posicao: ");
	scanf("%d",&position);

	if(position < 0 || position > object->qtdElements || object->qtdElements > TAM_LIST - 1) {
		printf("ERROR 586 - POSITION NOT EXIST IN LIST");
	} else {
		printf("| ---- EXIBINDO ELEMENTO. DA LISTA ---- | \n");
		printf("%c",object->atributo[position - 1]);
	}
}


//05 - Excluir um K_ésimo nó da lista
void removeElementOnFinal(nameStruct *object) {

    system("clear");

	if(object->qtdElements == 0) {
		printf("ERROR 986 - LIST NOT EXIST!");
	} else {
        printf("ELEMENTO REMOVIDA COM SUCESSO!");
		object->qtdElements--;
	}
}


//06 - Mostrar a maior nota da lista e o número da matricula do aluno
void findMatriculaOnList(nameStruct *object) {

    system("clear");

    int tam, maiorMatricula;
    float maiorNota=0;

    if(object->qtdElements == 0) {
        printf("ERROR 586 - LIST IS EMPTY");
    } else {
        printf("| ---- EXIBINDO ELEMENTOS DA LISTA ---- | \n");
        for(tam = 0; tam < object->qtdElements; tam++) {
            if(object->nota[tam] > maior) {
                maiorNota = object->nota[tam];
                maiorMatricula = object->matricula[tam];
            }
        }
        printf("A Maior nota e %f a matricula %d",maiorNota, maiorMatricula);
    }
}


//07 - inserir um novo nó após o K_Èsimo nó da lista.


//08 - Ordenar a lista
void orderList(nameStruct *object) {
    People temp;
    int lin, col, num;
	   
    for(lin = 0; lin < object->qtdElements; lin++) {	
    	for(col = lin; col < qtdElements; col++) {
    		if(object->matricula[lin] > object->matricula[col]) {
				temp = object[lin];
				object[lin] = object[col];
				object[col] = temp;
			}
		}
	}
    
    for(num = 0; num < tam; num++) {
		printf("%s \n",object[num->name);
		printf("%s \n",object[num->matricula);
    }
}


//09 - Gerar uma subcadeia ( sublista ) , somente com alunos a provados ( nota > 7 ) e mostrar na tela.
void createListOfAproved(nameStruct *object) {

}

//10 - mostrar todos os elementos da lista.
void showAllElements(nameStruct *object) {

    system("clear");

	int tam;
	if(object->qtdElements == 0) {
		printf("ERROR 586 - LIST IS EMPTY");
	} else {
		printf("| ---- EXIBINDO ELEMENTOS DA LISTA ---- | \n");
		for(tam = 0; tam < object->qtdElements; tam++) {
			printf("%c",object->atributo[tam]);
		}
	}
}



void exit() {

}


int menu() {

	nameStruct objeto;
	startList(&objeto);

  int op = -1;
  while (op != 0) {
        printf("\n#########################################################");
        printf("\n|                 AGENDA - MENU                         |");
        printf("\n|-------------------------------------------------------|");
        printf("\n|1 - Inserir no final da lista                          |");
        printf("\n|2 - Determinar o número de nós de uma lista            |");
        printf("\n|3 - Localizar o nó que contém uma determinada matricula|");
        printf("\n|4 - Mostrar o valor de um determinado no               |");
        printf("\n|5 - Excluir um K_ésimo nó da lista                     |");
        printf("\n|6 - Mostrar a maior nota da lista( Matricula aluno )   |");
        printf("\n|7 - inserir um novo nó após o K_Esimo no da lista      |");
        printf("\n|8 - Ordenar a lista                                    |");
        printf("\n|9 - Gerar uma subcadeia com alunos aprovados           |");
        printf("\n|10 - Mostrar todos os elementos da lista               |");
        printf("\n|0 - SAIR                                               |");
        printf("\n|-------------------------------------------------------|\n");

        scanf(" %d", &op);

        switch (op) {
            case 1:
                insertElementOnFinal(&objeto);
                break;
            case 2:
                cou
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                removeElementOnFinal(&objeto);
                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            case 10:
                showAllElements(&objeto);
                break;
            case 0:
                return 0;
                break;
        }

    }
}
