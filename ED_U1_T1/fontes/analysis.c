#include <stdio.h>
#include <stdlib.h>

#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "distribution_sort.h"



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
    printf("|                               1. SELECTION SORT                            |\n");
    printf("|                               2. INSERTION SORT BEST                       |\n");
    printf("|                               3. INSERTION SORT AVERAGE                    |\n");
    printf("|                               4. INSERTION SORT WORST                      |\n");
    printf("|                               5. MERGE SORT                                |\n");
    printf("|                               6. QUICK SORT BEST                           |\n");
    printf("|                               7. QUICK SORT AVERAGE                        |\n");
    printf("|                               8. QUICK SORT WORST                          |\n");
    printf("|                               9. DISTRIBUTION SORT MENOR K                 |\n");
    printf("|                              10. DISTRIBUTION SORT AVERAGE                 |\n");
    printf("|                              11. DISTRIBUTION SORT MAIOR K                 |\n");
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
            measure_ss(); 	
            break;

            case 2: 	
            measure_is_best();
            break;

            case 3:
            measure_is_average();
            break;

            case 4: 	
            measure_is_worst();
            break;

            case 5: 
            measure_ms();	
            break;

            case 6: 
            measure_qs_best();	
            break;

            case 7: 	
            measure_qs_average();
            break;

            case 8: 	
            measure_qs_worst();
            break;

            case 9: 	
            measure_ds_menor_k();
            break;

            case 10: 	
            measure_ds_average();
            break;

            case 11: 	
            measure_ds_maior_k();
            break;
        }
	} while (op1 != 0);
    printf("Finish\n");
    return 0;
}