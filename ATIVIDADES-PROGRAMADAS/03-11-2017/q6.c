/*
DISCIPLINA: ESTRUTURA DE DADOS
PROFESSOR: JOSÉ HONORATO FERREIRA NUNES
DATA DA AULA : 03/11/2017
DATA DA ENTREGA : 09/11/2017
ENVIAR P/ : honoratonunes@gmail.com

Escrever um programa que cadastre vários produtos. Em seguida,
imprima uma lista com o código e nome da cada produto. Por último,
consulte o preço de um produto através de seu código.
*/

#include <stdio.h>
#include <locale.h>

typedef struct {
    char cod[5];
    char nome[50];
    float preco;
} Produto;

void inserirProduto(Produto *listaProduto, int tam);

main() {
	setlocale(LC_ALL,"portuguese_Brazil");

    Produto listaProdutos[2];
    inserirProduto(listaProdutos, 2);
    buscaPorCodigo(listaProdutos, 2);
}

void inserirProduto(Produto *listaProduto, int tam) {
    int num;

    for(num = 0; num < tam; num++) {
        printf("### inserindo dados do %d� Produto ### \n",num+1);
        printf("Digite o codigo do produto: ");
        scanf("%s",listaProduto[num].cod);
        printf("Digite o nome do produto: ");
        scanf("%s",listaProduto[num].nome);
        printf("digite o preco do produto: ");
        scanf("%f",&listaProduto[num].preco);
        printf("### ------------------------- #### \n");
    }

}

void buscaPorCodigo(Produto *listaProduto, int tam) {
    int num;
    char codigo[5];
    printf("Digite o c�digo que deseja buscar: ");
    scanf("%s",codigo);
    for(num = 0; num < tam; num++) {
        if(strcmp(codigo,listaProduto[num].cod) == 0) {
            printf("Produto => %s \t\t\t",listaProduto[num].nome);
            printf("Valor => %f",listaProduto[num].preco);
        }
    }
}

