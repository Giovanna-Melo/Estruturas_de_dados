#include <stdio.h>
#include <stdlib.h>

#include "arvore_binaria.h"
#include "avl.h"
#include "tabela_dispersao.h"



int principal(void);

int principal(void)
{
    int op1;
    //system("clear||cls");
    printf("\n");
    printf("------------------------------------------------------------------------------\n");
    printf("                                MENU PRINCIPAL                                \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}\n");
    printf("|                                                                            |\n");
    printf("|                               1. ÁRVORE BINÁRIA AVERAGE                    |\n");
    printf("|                               2. ÁRVORE BINÁRIA WORST                      |\n");
    printf("|                               3. ÁRVORE AVL AVERAGE                        |\n");
    printf("|                               4. ÁRVORE AVL WORST                          |\n");
    printf("|                               5. TABELA DE DISPERSÃO AVERAGE               |\n");
    printf("|                               6. TABELA DE DISPERSÃO WORST                 |\n");
    printf("|                               0. SAIR                                      |\n");
    printf("|                                                                            |\n");
    printf("{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}\n\n");
    printf("Option:");
    scanf("%d", &op1);
    return op1;
}

int main()
{
    int op1;
	do 
    {
		op1 = principal();
        switch(op1) 
        {
            case 1:
            measure_bta(); 	
            break;

            case 2: 	
            measure_btw();
            break;

            case 3:
            measure_avl_average();
            break;

            case 4: 	
            measure_avl_worst();
            break;

            case 5: 
            measure_tda();	
            break;

            case 6: 
            measure_tdw();	
            break;

            //case 7: 	
            //teste();
            //break;
        }
	} while (op1 != 0);
    printf("Finish\n");
    return 0;
}

