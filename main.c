#include <time.h>
#include <sys/time.h>
#include "defs.h"

#define MICRO_PER_SECOND 1000000
#define POPULACAO 100
#define GENERATIONS 1000

int main()
{
    /********************* Declaração de Variáveis ********************/
    int PERIODOS;
    int ESPECIES;
    int TERRENOS;
    int PERIODOS_ANO;
    
    int *temp_proc; // tempos de precessamento
    int *lucratividade_especies;

    int **per_plantio;  // intervalos de plantio [Ei,Ti]
    
    /* variáveis referentes ao algoritmo genético */
    individuo *populacao;
    
    /* variáveis utilizadas no cálculo do tempo de execução */
    struct timeval start_time;
    struct timeval stop_time;
    double resul;

    gettimeofday(&start_time, NULL);
    srand((double) time(NULL)); // rand() baseada na hora do computador

    /* variáveis auxiliares */
    int i;
    
    /*************************** LEITURA ******************************/
    lerDados(&PERIODOS_ANO,
              &PERIODOS,
              &ESPECIES,
              &TERRENOS,
              &temp_proc,
              &per_plantio,
              &lucratividade_especies);
    
    /*************************** INIT ******************************/
    
    populacao = (individuo *)malloc(POPULACAO * sizeof(individuo));
    for (i = 0; i < POPULACAO; i++)
    {
        populacao[i] = criarIndividuo(PERIODOS,
                                      ESPECIES,
                                      TERRENOS,
                                      temp_proc,
                                      per_plantio,
                                      PERIODOS_ANO,
                                      lucratividade_especies);
    }
        
    /*************************** GENETICO ******************************/
    
    ordenarPopulacao(populacao, POPULACAO);
    
    for (i = 0; i < GENERATIONS; i++)
    {
        runGeneration(populacao,
                       POPULACAO,
                       PERIODOS,
                       TERRENOS,
                       lucratividade_especies,
                       ESPECIES,
                       PERIODOS_ANO,
                       temp_proc,
                       per_plantio);
    }
    
    displayIndividuo(populacao[0],
                     PERIODOS,
                     TERRENOS);
    displayBestFObj(populacao,
                    POPULACAO);
    
    /*************************** TEST ******************************/
    
    /*************************** PRINT ******************************/
    gettimeofday(&stop_time, NULL);
    resul = (double)(stop_time.tv_sec - start_time.tv_sec);
    resul += (stop_time.tv_usec - start_time.tv_usec)/(double)MICRO_PER_SECOND;
    printf("Tempo: %lf (s)\n", resul);  // em segundos

//    printf("%d %d %d %d\n",PERIODOS_ANO,PERIODOS,ESPECIES,TERRENOS);
//
//    for(i = 0; i<ESPECIES;i++)
//        printf("%d ",temp_proc[i]);
//    printf("\n");
//
//    for (i = 0;i<ESPECIES;i++)
//    {
//        for (j=0;j<2;j++)
//        {
//            printf("%d ",per_plantio[i][j]);
//        }
//        printf("\n");
//    }
//
//    for (i = 0;i<ESPECIES;i++)
//    {
//        printf("%d ",lucratividade_especies[i]);
//    }
//    printf("\n");
//
//    printf("\nP_INDIVIDUO i: \n");
//    for(i=0;i<TERRENOS;i++)
//    {
//        for(j=0;j<PERIODOS;j++)
//        {
//            printf("%d ", populacao[0].sol[i][j]);
//        }
//        printf("\n");
//    }
//    for (i=0;i<POPULACAO;i++)
//        printf("%d ",populacao[i].f_obj);
//    printf("\n");

    return 0;
}
