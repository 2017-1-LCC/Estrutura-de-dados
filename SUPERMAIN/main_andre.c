// por hora só o menu

#include <stdio.h>

int menu();

int menu()
{
  int op = -1
  while (op != 0) {
        printf("\n#########################################################");
        printf("\n|                 AGENDA - MENU                         |");
        printf("\n|-------------------------------------------------------|");
        printf("\n|1 - CADASTRAR CONTATO                                  |");
        printf("\n|2 - BUSCAR CONTATO POR NOME                            |");
        printf("\n|3 - BUSCAR CONTATO POR MES DE ANIVERSARIO              |");
        printf("\n|4 - BUSCAR POR DIA E MES DE ANIVERSARIO                |");
        printf("\n|5 - IMPRIMIR AGENDA PARCIALMENTE                       |");
        printf("\n|6 - IMPRIMIR AGENDA COMPLETA                           |");
        printf("\n|7 - EXCLUIR CONTATO                                    |");
        printf("\n|0 - SAIR                                               |");
        printf("\n|-------------------------------------------------------|\n");

        scanf(" %d", &op);
        switch (op) {
            case 1:
                cadastrar(agenda, &chave);
                break;
            case 2:
                buscarNome(agenda, chave);
                break;
            case 3:
                buscarMes(agenda, chave);
                break;
            case 4:
                buscarDiaMes(agenda, chave);
                break;
            case 5:
                imprimeParcial(agenda, chave);
                break;
            case 6:
                imprimeTotal(agenda, chave);
                break;
            case 7:
                excluir(agenda, chave);
                break;
            case 0:
                return 0;
                break;

        }

    }
}

int main()
{
    menu();
    return 0;
}
