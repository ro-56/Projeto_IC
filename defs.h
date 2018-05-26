#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
//#include <string.h>
//#include <malloc/malloc.h>
//#include <malloc.h>
//#include <limits.h>
/*********************** FUNCTIONS ***********************/

/*** INDIVIDUO ***/
typedef struct individuo
{
    int f_obj;
    int **sol;
} individuo;

individuo criar_individuo (int PERIODOS,
                           int ESPECIES,
                           int TERRENOS,
                           int *temp_proc,
                           int **per_plantio,
                           int PERIODOS_ANO,
                           int *lucratividade_especies);
int create_row (int *row,
                int ESPECIES,
                int PERIODOS,
                int PERIODOS_ANO,
                int *temp_proc,
                int **per_plantio,
                int *lucratividade_especies);

/*** LEITURA ***/

void ler_dados (int *PERIODOS_ANO, 
                int *PERIODOS,
                int *ESPECIES,
                int *TERRENOS,
                int **temp_proc,
                int ***per_plantio,
                int **lucratividade_especies);


/*** GENETICO ***/

void ordenar_populacao(individuo *populacao,
                       int POPULACAO);

void run_generation(individuo *populacao,
                    int POPULACAO,
                    int PERIODOS,
                    int TERRENOS,
                    int *lucratividade_especies);




