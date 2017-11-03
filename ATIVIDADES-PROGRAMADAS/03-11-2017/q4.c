/*
DISCIPLINA: ESTRUTURA DE DADOS
PROFESSOR: JOSÃ‰ HONORATO FERREIRA NUNES
DATA DA AULA : 03/11/2017
DATA DA ENTREGA : 09/11/2017
ENVIAR P/ : honoratonunes@gmail.com

Escrever um programa que cadastre o nome, a matrÃ­cula e duas notas
de vÃ¡rios alunos. Em seguida imprima a matrÃ­cula, o nome e a mÃ©dia de
cada um deles.
*/

#include <stdio.h>
#include <locale.h>

/* STRUCT com as informações do Aluno */
typedef struct {
    char nome[20];
    int matricula;
    float primeiraNota;
    float segundaNota;
} Aluno;


/* DECLARAÇÃO DOS MÉTODOS */
void insertAndPrintInfoAlunos( Aluno *vetorAluno, int tamanho);

main() {
	setlocale(LC_ALL,"portuguese_Brazil");
	
	
    Aluno alunoList[2];
    insertAndPrintInfoAlunos(alunoList, 2);
}

/*
função que insere e mostra os dados do aluno
*/
void insertAndPrintInfoAlunos( Aluno *vetorAluno, int tamanho) {
    int num;
    float avrg;
    
	/* 
		um for que acessa cada posição no vetor de Alunos e através do . ( ponto ) da pra acessar a propriedade
		do struct, exemplo : vetor[num].nome
	*/	
    for(num = 0; num < tamanho; num++)  {
    	printf("###  PREENCHENDO INFORMAÇÕES DO %dº ALUNO ### \n\n",num+1);
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
		vetor que mostra as informações 
	*/
    for(num = 0; num < tamanho; num++)  {
    	printf("###  EXIBINDO INFORMAÇÕES DO DO %dº ALUNO ### \n\n",num+1);
        printf("Matricula : %d \n",vetorAluno[num].matricula);
        printf("Nome : %s \n",vetorAluno[num].nome);
        // PROCESSAMENTO PARA EXIBIR A MÉDIA 
        printf("Media : %f \n",(vetorAluno[num].primeiraNota + vetorAluno[num].segundaNota) / 2);
        printf("### --            ==================           --##");
        printf("\n\n\n");
    }

}
