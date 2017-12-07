#include <stdio.h>

//CONSTANTE 
#define TAMANHODAFILA 5

/* 
- DECLARAÇÃO DA STRUCT COM AS CARACTERISTICAS DA FILA 
- inicio e fim sao atributos para manipular a fila
*/
typedef struct {
	int inicio, fim;
	int matricula[TAMANHODAFILA];
	float nota_trab[TAMANHODAFILA];
	float nota_prova[TAMANHODAFILA];
}Fila;


/*
- DECLARAÇÃO DO CORPO DAS FUNÇÕES
*/
void inicializaFila(Fila *fila);
void inserirNaFila(Fila *fila);
void excluirDaFila(Fila *fila);
void exibirFila(Fila *fila);
void exibirMaiorMedia(Fila *fila);
void exibirPrimeiroDaFila(Fila *fila);


/*
- START 
*/
main() {
	menu();
}

void inicializaFila(Fila *fila) {
	fila->inicio = 0;
	fila->fim = -1;
}
void inserirNaFila(Fila *fila) {
	float nota_trab, nota_prova;
	int matricula;
	
	printf("INSERINDO NOVO ALUNO NA FILA \n");
	
	printf("Digite a matricula do aluno: ");
	scanf("%d",&matricula);

	printf("Digite a nota do trabalho: ");
	scanf("%f",&nota_trab);
	
	printf("Digite a nota da prova: ");
	scanf("%f",&nota_prova);
	
	if(fila->fim == TAMANHODAFILA - 1) {
		printf("Fila cheia!\n");
	} else {
		fila->fim++;
		fila->matricula[fila->fim] = matricula;
		fila->nota_trab[fila->fim] = nota_trab;
		fila->nota_prova[fila->fim] = nota_prova;	
	}
}

void excluirDaFila(Fila *fila) {
	if (fila->fim < fila->inicio){
		printf("Fila vazia!\n");
	}
	else{
		fila->inicio++;
	}
}

void exibirFila(Fila *fila) {
	int i;
	for (i = fila->inicio; i <= fila->fim; i++){
		printf("Matricula: %d | Trabalho: %f | Prova: %f \n", fila->matricula[i], fila->nota_trab[i], fila->nota_prova[i]);
	}
}

void exibirMaiorMedia(Fila *fila) {
	int i;
	float media;
	for (i = fila->inicio; i <= fila->fim; i++){
		media = (fila->nota_prova[i] + fila->nota_trab[i])/2;
		if(media >= 7) {
			printf("Matricula: %d | Trabalho: %f | Prova: %f \n", fila->matricula[i], fila->nota_trab[i], fila->nota_prova[i]);
		}
		
	}
}
void exibirPrimeiroDaFila(Fila *fila) {
	int i;
	if (fila->fim < fila->inicio){
		printf("Fila vazia!\n");
	}
	else{
		printf("Matricula: %d | Trabalho: %f | Prova: %f \n", fila->matricula[fila->inicio], fila->nota_trab[fila->inicio], fila->nota_prova[fila->inicio]);
	}
}


int menu() {

	Fila objeto;
	inicializaFila(&objeto);

  int op = -1;
  while (op != 0) {
        printf("\n#########################################################");
        printf("\n|              OPERACOES DOM FILA                       |");
        printf("\n|-------------------------------------------------------|");
        printf("\n|1 - Inserir na fila                                    |");
        printf("\n|2 - Excluir da fila                                    |");
        printf("\n|3 - Exibir fila                                        |");
        printf("\n|4 - Exibir matricula com maior media                   |");
        printf("\n|5 - Exibir primeiro elemento da fila                   |");
        printf("\n|0 - SAIR                                               |");
        printf("\n|-------------------------------------------------------|\n");

        scanf(" %d", &op);

        switch (op) {
            case 1:
                inserirNaFila(&objeto);
                break;
                
            case 2:
                excluirDaFila(&objeto);
                break;
                
            case 3:
				exibirFila(&objeto);
                break;
                
            case 4:
				exibirMaiorMedia(&objeto);
                break;
                
            case 5:
            	exibirPrimeiroDaFila(&objeto);
                break;
                
            case 0:
            	
                return 0;
                break;
        }

    }
}
