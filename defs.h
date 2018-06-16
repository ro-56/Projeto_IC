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

individuo criarIndividuo (int PERIODOS,
                           int ESPECIES,
                           int TERRENOS,
                           int *temp_proc,
                           int **per_plantio,
                           int PERIODOS_ANO,
                           int *lucratividade_especies);

int createRow (int *row,
                int ESPECIES,
                int PERIODOS,
                int PERIODOS_ANO,
                int *temp_proc,
                int **per_plantio,
                int *lucratividade_especies);

/*** LEITURA ***/

void lerDados (int *PERIODOS_ANO, 
                int *PERIODOS,
                int *ESPECIES,
                int *TERRENOS,
                int **temp_proc,
                int ***per_plantio,
                int **lucratividade_especies);


/*** GENETICO ***/

void ordenarPopulacao(individuo *populacao,
                      int POPULACAO);

void runGeneration(individuo *populacao,
                   int POPULACAO,
                   int PERIODOS,
                   int TERRENOS,
                   int *lucratividade_especies,
                   int ESPECIES,
                   int PERIODOS_ANO,
                   int *temp_proc,
                   int **per_plantio);

/*** RESULTADOS ***/

void displayAverageFObj(individuo *group,
                        int POPULACAO);

void displayBestFObj(individuo *group,
                     int POPULACAO);

/*
void display_best_individuo(individuo *group,
                            int POPULACAO,
                            int PERIODOS,
                            int TERRENOS);
*/

void displayIndividuo(individuo object,
                       int PERIODOS,
                       int TERRENOS);

float getAverageFObj(individuo *group,
                     int POPULACAO);

int getBestFObj(individuo *group,
                int POPULACAO);
