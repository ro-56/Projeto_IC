#include "defs.h"


void displayAverageFObj(individuo *group,
                        int POPULACAO)
{
    printf("\nAverage F_obj: %.4f\n", getAverageFObj(group,
                                                     POPULACAO));
    return;
}
/*********/
void displayBestFObj(individuo *group,
                     int POPULACAO)
{
    printf("\nBest F_obj: %d\n", getBestFObj(group,
                                             POPULACAO));
    return;
}
/*********/
/*
void display_best_individuo(individuo *group,
                            int POPULACAO,
                            int PERIODOS,
                            int TERRENOS)
{
    int i, j, best_fobj = 0, best_fobj_idx;;
    
    for (i = 0; i < POPULACAO; i++)
    {
        if (group[i].f_obj > best_fobj)
            best_fobj_idx = i;
    }
    
    printf("\nIndividuo:\n");
    for (i = 0; i < TERRENOS; i++)
    {
        for (j = 0; j < PERIODOS; j++)
        {
            printf("%d ",group[best_fobj_idx].sol[i][j]);
        }
        printf("\n");
    }
    printf("---------------\n");
    
    return;
}
*/
/*********/
void displayIndividuo(individuo object,
                      int PERIODOS,
                      int TERRENOS)
{
    int i, j;
    
    printf("\nIndividuo:\n");
    for (i = 0; i < TERRENOS; i++)
    {
        for (j = 0; j < PERIODOS; j++)
        {
             printf("%d ",object.sol[i][j]);
        }
        printf("\n");
    }
    printf("---------------\n");
    
    return;
}
/***************************/
float getAverageFObj(individuo *group,
                     int POPULACAO)
{
    float average, sum_fobj = 0;;
    int i;
    
    for (i = 0; i < POPULACAO; i++)
    {
        sum_fobj += group[i].f_obj;
    }
    
    average = sum_fobj / (float)POPULACAO;
    
    return average;
}
/*********/
int getBestFObj(individuo *group,
                int POPULACAO)
{
    int i, best_fobj = 0;
    
    for (i = 0; i < POPULACAO; i++)
    {
        if (group[i].f_obj > best_fobj)
            best_fobj = group[i].f_obj;
    }
    
    return best_fobj;
}
/*********/
