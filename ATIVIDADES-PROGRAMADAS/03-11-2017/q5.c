/*
DISCIPLINA: ESTRUTURA DE DADOS
PROFESSOR: JOSÉ HONORATO FERREIRA NUNES
DATA DA AULA : 03/11/2017
DATA DA ENTREGA : 09/11/2017
ENVIAR P/ : honoratonunes@gmail.com

Escrever um programa que cadastre o nome, a altura, o peso, o cpf e
sexo de algumas pessoas. Com os dados cadastrados, em seguida
localizar uma pessoas através do seu CPF e imprimir o seu IMC.
*/

#include <stdio.h>
#include <locale.h>

typedef struct {
    char nome[20];
    float altura;
    float peso;
    char cpf[11];
    char sexo;
} Pessoa;

void inserirPessoa(Pessoa *listaPessoa, int tam);
void buscaByCPF(Pessoa *listaPessoa, int tam);

main() {
	setlocale(LC_ALL,"portuguese_Brazil");

    Pessoa listaPessoas[2];
    inserirPessoa(listaPessoas, 2);
    buscaByCPF(listaPessoas, 2);
}

void buscaByCPF(Pessoa *listaPessoa, int tam) {
    int num;
    char cpf[11];
    printf("Favor digitar o cpf a ser encontrado na base: ");
    scanf("%s",cpf);

    for(num = 0; num < tam; num++) {
        if(strcmp(cpf,listaPessoa[num].cpf) == 0) {
            printf("CPF localizado na pessoa: %s \n",listaPessoa[num].nome);
            printf("CPF: %s \n",listaPessoa[num].cpf);
            printf("IMC: %f \n",listaPessoa[num].peso/(listaPessoa[num].altura * listaPessoa[num].altura));
        }
    }  
}

void inserirPessoa(Pessoa *listaPessoa, int tam) {
    int num;

    for(num = 0; num < tam; num++) {
        printf("### Inserir os valores para pessoa ### \n");
        printf("Digite o nome da pessoa:");
        scanf("%s",listaPessoa[num].nome);
        printf("Digite a altura da pessoa:");
        scanf("%f",&listaPessoa[num].altura);
        printf("Digite o peso da pessoa:");
        scanf("%f",&listaPessoa[num].peso);
        printf("Digite o CPF da pessoa:");
        scanf("%s",listaPessoa[num].cpf);
        printf("Digite o sexo da pessoa:");
        scanf("%c",&listaPessoa[num].sexo);
        printf("### ------------------------------- ### \n");
    }

}

