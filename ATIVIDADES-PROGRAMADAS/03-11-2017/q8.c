/*

a) -> 

b) -> 

*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// a) -> 
typedef struct {
    char rua[10];
    int numero;
    char complemento[10];
    char bairro[10];
    char cep[10];
    char cidade[20];
    char estado[20];
    char pais[20];
} Address;

typedef struct {
    char ddd[2];
    char numero[9];
} Phone;

typedef struct {
    char dia[1];
    char mes[1];
    char ano[3];
} DateNascimento;

typedef struct {
    char nome[10];
    char email[20];
    Address endereco;
    Phone telefone;
    DateNascimento dtNasc;
    char observacao[20];
} People;

typedef struct {
	//b) ->
    People peopleInList[10];
} BookingSchedule;


void insertPeopleOnBookingSchedule(BookingSchedule *schedule, int tam);
void showListBookingSchedule(BookingSchedule *schedule, int tam);
void findByFirstName(BookingSchedule *schedule, int tam);

int menu();

main() {
    setlocale(LC_ALL,"portuguese_Brazil");
	BookingSchedule schedule;
	
	int m, qntPeople;
	m = menu();
	
	switch (m){	
		case 1:
			printf("Quantas pessoas deseja inserir na agenda? \n");	
			scanf("%d",&qntPeople);
			if(qntPeople > 10) {
				while(qntPeople > 10) {
					printf("O numero maximo de clientes � 10 \n");
					scanf("%d",&qntPeople);
					if(qntPeople <= 10) {
						insertPeopleOnBookingSchedule(&schedule, qntPeople);
					}
				}
			} else {
				insertPeopleOnBookingSchedule(&schedule, qntPeople);
			}	
		break;	
		
		case 2:	
			showListBookingSchedule(&schedule, 2);
		break;
		
		case 3:	
		
		break;
	}
    
    m = menu();
    
}

insertPeopleOnBookingSchedule(BookingSchedule *schedule, int tam) {
    int num;

    for(num = 0; num < tam; num++) {
        printf("### Inserindo Pessoas na agenda ### \n");
        printf("Digite o nome da pessoa: ");
        scanf("%s",schedule->peopleInList[num].nome);
        printf("Digite o email da pessoa: ");
        scanf("%s",schedule->peopleInList[num].email);
        printf("### ---- Informações do endereço da pessoa ---- ### \n");
        printf("Digite a rua da pessoa: ");
        scanf("%s",schedule->peopleInList[num].endereco.rua);
        printf("Digite o numero da pessoa: ");
        scanf("%d",&schedule->peopleInList[num].endereco.numero);
        printf("Digite o complemento da pessoa: ");
        scanf("%s",schedule->peopleInList[num].endereco.complemento);
        printf("Digite o bairro da pessoa: ");
        scanf("%s",schedule->peopleInList[num].endereco.bairro);
        printf("Digite o cep da pessoa: ");
        scanf("%s",schedule->peopleInList[num].endereco.cep);
        printf("Digite a cidade da pessoa: ");
        scanf("%s",schedule->peopleInList[num].endereco.cidade);
        printf("Digite o estado da pessoa: ");
        scanf("%s",schedule->peopleInList[num].endereco.estado);
        printf("Digite o pais da pessoa: ");
        scanf("%s",schedule->peopleInList[num].endereco.pais);
        printf("### ---- Informações do telefone da pessoa ---- ### \n");
        printf("Digite o DDD da pessoa: ");
        scanf("%s",schedule->peopleInList[num].telefone.ddd);
        printf("Digite o numero do celular da pessoa: ");
        scanf("%s",schedule->peopleInList[num].telefone.numero);
        printf("### ---- Informações da data de nascimento da pessoa ---- ### \n");
        printf("Digite o dia: ");
        scanf("%s",schedule->peopleInList[num].dtNasc.dia);
        printf("Digite o mes: ");
        scanf("%s",schedule->peopleInList[num].dtNasc.mes);
        printf("Digite o ano: ");
        scanf("%s",schedule->peopleInList[num].dtNasc.ano);
        printf("### ---- Observacao ----- ### \n");
        printf("Digite a observação : ");
        scanf("%s",schedule->peopleInList[num].observacao);
    }

}

showListBookingSchedule(BookingSchedule *schedule, int tam) {
    int num;
	printf("### Pessoas cadastradas na agenda ### \n\n");
	printf("|Index\t|Nome\t|E-mail\t|Rua \t|Numero\t|Complemento\t|Bairro\t|CEP\t|Cidade\t|Estado\t|Pais\t|DDD\t|Telefone\t|Dia\t|Mes\t|Ano\t|Observacao|\n");
    for(num = 0; num < tam; num++) {
    	printf("|%d\t|%s\t|%s\t|%d\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|%s\t|",&num,schedule->peopleInList[num].nome,schedule->peopleInList[num].email,
		schedule->peopleInList[num].endereco.rua, &schedule->peopleInList[num].endereco.numero, schedule->peopleInList[num].endereco.complemento,
		schedule->peopleInList[num].endereco.bairro, schedule->peopleInList[num].endereco.cep, schedule->peopleInList[num].endereco.cidade,
		schedule->peopleInList[num].endereco.estado, schedule->peopleInList[num].endereco.pais, schedule->peopleInList[num].telefone.ddd,
		schedule->peopleInList[num].telefone.numero, schedule->peopleInList[num].dtNasc.dia, schedule->peopleInList[num].dtNasc.mes,
		schedule->peopleInList[num].dtNasc.ano, schedule->peopleInList[num].observacao);
        //printf("### X----X-----X-----X------X ### - Proximo registro"); 
    }
}

void findByFirstName(BookingSchedule *schedule, int tam) {
	int num;
	char nome[10];
	printf("Digite o nome que deseja buscar: ");
	scanf("%s",nome);
	for(num = 0; num < tam; num++) { 
		if(strcmp(nome,schedule->peopleInList[num].nome) == 0) {
	    	printf("### CLIENTE ENCONTRADO ### \n");
	        printf("Nome => %s \n",schedule->peopleInList[num].nome);
	        printf("E-mail => %s \n",schedule->peopleInList[num].email);
	        printf("Rua => %s \n",schedule->peopleInList[num].endereco.rua);
	        printf("Numero => %d \n",&schedule->peopleInList[num].endereco.numero);
	        printf("Complemento => %s \n",schedule->peopleInList[num].endereco.complemento);
	        printf("Bairro => %s \n",schedule->peopleInList[num].endereco.bairro);
	        printf("CEP => %s \n",schedule->peopleInList[num].endereco.cep);
	        printf("Cidade => %s \n",schedule->peopleInList[num].endereco.cidade);
	        printf("Estado => %s \n",schedule->peopleInList[num].endereco.estado);
	        printf("Pais => %s \n",schedule->peopleInList[num].endereco.pais);
	        printf("DDD => %s \n",schedule->peopleInList[num].telefone.ddd);
	        printf("Telefone => %s \n",schedule->peopleInList[num].telefone.numero);
	        printf("Dia => %s \n",schedule->peopleInList[num].dtNasc.dia);
	        printf("Mes => %s \n",schedule->peopleInList[num].dtNasc.mes);
	        printf("Ano => %s \n",schedule->peopleInList[num].dtNasc.ano);
	        printf("Observacao => %s \n",schedule->peopleInList[num].observacao);		
		}
	}
}

int menu(){
	int menu;
	
	//system("clear");
	
	printf("\t\tMenu \n");
	printf("\t\t1 - Cadastrar pessoas na agenda \n");
	printf("\t\t2 - Imprimir: Todos os dados \n");
	printf("\t\t3 - Buscar por nome \n");
	printf("\t\t4 - Buscar por mes \n");
	printf("\t\t5 - Buscar por dia e mes \n");
	printf("\t\t6 - Inserir \n");
	printf("\t\t7 - Retirar \n");
	printf("\t\t8 - Sair \n");
		
	printf("Opecao desejada = ");
	scanf("%d", &menu);
	return menu;
}
