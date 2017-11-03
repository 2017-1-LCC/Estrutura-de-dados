/*
DISCIPLINA: ESTRUTURA DE DADOS
PROFESSOR: JOSÉ HONORATO FERREIRA NUNES
DATA DA AULA : 03/11/2017
DATA DA ENTREGA : 09/11/2017
ENVIAR P/ : honoratonunes@gmail.com

GIST : https://gist.github.com/hc3/83876f4a6efdec078214b5e0e13a4a85
VETOR de Struct : https://programacaodescomplicada.wordpress.com/2012/08/31/aula-37-arrays-de-structs/


Escrever um programa que cadastre o nome, a matrícula e duas notas
de vários alunos. Em seguida imprima a matrícula, o nome e a média de
cada um deles.
*/

#include <stdio.h>
#include <locale.h>

/* STRUCT com as informa��es do Aluno */
typedef struct {
    char nome[20];
    int matricula;
    float primeiraNota;
    float segundaNota;
} Aluno;


/* DECLARA��O DOS M�TODOS */
void insertAndPrintInfoAlunos( Aluno *vetorAluno, int tamanho);

main() {
	setlocale(LC_ALL,"portuguese_Brazil");
	
	
    Aluno alunoList[2];
    insertAndPrintInfoAlunos(alunoList, 2);
}

/*
fun��o que insere e mostra os dados do aluno
*/
void insertAndPrintInfoAlunos( Aluno *vetorAluno, int tamanho) {
    int num;
    float avrg;
    
	/* 
		um for que acessa cada posi��o no vetor de Alunos e atrav�s do . ( ponto ) da pra acessar a propriedade
		do struct, exemplo : vetor[num].nome
	*/	
    for(num = 0; num < tamanho; num++)  {
    	printf("###  PREENCHENDO INFORMA��ES DO %d� ALUNO ### \n\n",num+1);
        printf("Digite o nome do aluno: ");
        scanf("%s",vetorAluno[num].nome);
        printf("Digite a matricula do aluno: ");
        scanf("%d",&vetorAluno[num].matricula);
        printf("Digite a primeira nota do aluno: ");
        scanf("%f",&vetorAluno[num].primeiraNota);
        printf("Digite a segunda nota do aluno: ");
        scanf("%f",&vetorAluno[num].segundaNota);
        printf("### -- FIM CADASTRO DO ALUNO : %s",vetorAluno[num].nome);
        printf("\n\n\n");
    }
	
	/* 
		vetor que mostra as informa��es 
	*/
    for(num = 0; num < tamanho; num++)  {
    	printf("###  EXIBINDO INFORMA��ES DO DO %d� ALUNO ### \n\n",num+1);
        printf("Matricula : %d \n",vetorAluno[num].matricula);
        printf("Nome : %s \n",vetorAluno[num].nome);
        // PROCESSAMENTO PARA EXIBIR A M�DIA 
        printf("Media : %f \n",(vetorAluno[num].primeiraNota + vetorAluno[num].segundaNota) / 2);
        printf("### --            ==================           --##");
        printf("\n\n\n");
    }

}
