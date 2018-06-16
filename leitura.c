#include "defs.h"

char nome[] = "entrada.txt";

void lerDados (int *PERIODOS_ANO, int *PERIODOS, int *ESPECIES, int *TERRENOS, int **temp_proc, int ***per_plantio, int **lucratividade_especies)
{
    FILE *f;
    char trash[255];
    int i, j;
    
    f = fopen(nome, "r");
    if (f == NULL)
    {
        perror(nome);
        exit (1);
    }
    
/*****/
    fscanf(f, "%s", trash);
    fscanf(f, "%d", PERIODOS_ANO);
    
/*****/
    fscanf(f, "%s", trash);
    fscanf(f, "%d", PERIODOS);
    
/*****/
    fscanf(f, "%s", trash);
    fscanf(f, "%d", ESPECIES);
    
/*****/
    fscanf(f, "%s", trash);
    fscanf(f, "%d", TERRENOS);
    
/*****/
    *temp_proc = (int *)malloc(*ESPECIES * sizeof(int));
    
    fscanf(f, "%s", trash);
    for (i = 0; i < *ESPECIES; i++)
        fscanf(f, "%d", &(*temp_proc)[i]);
    
/*****/
    *per_plantio = (int **)malloc(*ESPECIES * sizeof(int*));
    for(i = 0; i < *ESPECIES; i++)
        (*per_plantio)[i] = (int *)malloc(2 * sizeof(int));
    
    fscanf(f, "%s", trash);
    for(i = 0; i < *ESPECIES; i++)
    {
        for(j = 0; j < 2; j++)
        {
            fscanf(f, "%d", &(*per_plantio)[i][j]);
        }
    }
    
/*****/
    *lucratividade_especies = (int *)malloc(*ESPECIES * sizeof(int));
    
    fscanf(f, "%s", trash);
    for (i = 0; i < *ESPECIES; i++)
        fscanf(f, "%d", &(*lucratividade_especies)[i]);
    
    
    fclose(f);
}
