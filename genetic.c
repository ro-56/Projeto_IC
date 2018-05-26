#include "defs.h"
#include "genetic.h"

#define PROBABILIDADE_CROSSOVER 0.9
#define PROBABILIDADE_MUTACAO 0.01
#define MAX_CROSSOVER_PERCENTAGE 0.6

void run_generation(individuo *populacao,
                    int POPULACAO,
                    int PERIODOS,
                    int TERRENOS,
                    int *lucratividade_especies)
{
    /*************************** MALLOC ******************************/
    int i,j;
    
    individuo *filhos, *mista, pai1, pai2;
    int *indPai1, *indPai2;
    
    filhos = (individuo *)malloc(POPULACAO * sizeof(individuo));
    for (i = 0; i < POPULACAO; i++)
    {
        filhos[i].sol = (int **)malloc(TERRENOS * sizeof(int *));
        for (j = 0; j < TERRENOS; j++)
        {
            filhos[i].sol[j] = (int *)malloc(PERIODOS * sizeof(int));
        }
    }
    
    mista = (individuo *)malloc((2 * POPULACAO) * sizeof(individuo));
    for (i = 0; i < 2*POPULACAO; i++)
    {
        mista[i].sol = (int **)malloc(TERRENOS * sizeof(int *));
        for (j = 0; j < TERRENOS; j++)
        {
            mista[i].sol[j] = (int *)malloc(PERIODOS * sizeof(int));
        }
    }
    
    indPai1 = (int *)malloc(POPULACAO * sizeof(int));
    indPai2 = (int *)malloc(POPULACAO * sizeof(int));

    
    /*************************** GENERATION ******************************/
    
    gerar_conjunto_pais(populacao, indPai1, indPai2, POPULACAO);
    
    for (i = 0; i < POPULACAO; i += 2)
    {
        //torneio
        pai1 = torneio(populacao[indPai1[i]], populacao[indPai2[i]]);
        pai2 = torneio(populacao[indPai1[i]], populacao[indPai2[i]]);
        
        //crossover
        crossover(pai1,
                  pai2,
                  &(filhos[i]),
                  &(filhos[i+1]),
                  PERIODOS,
                  TERRENOS,
                  lucratividade_especies);
        
        //mutacao
        
    }
    //populacao resultante
//    ordenar_populacao(filhos,POPULACAO);
    
    merge_populations(populacao,
                      filhos,
                      mista,
                      PERIODOS,
                      TERRENOS,
                      POPULACAO);
    
    ordenar_populacao(mista, 2*POPULACAO);
    
    make_new_population(populacao, mista, POPULACAO);
    
    
    /*************************** FREE ******************************/
    
    for (i = 0; i < POPULACAO; i++)
    {
        for (j = 0; j < TERRENOS; j++)
        {
            free(filhos[i].sol[j]);
        }
        free(filhos[i].sol);
    }
    free(filhos);
    free(mista);
    free(indPai1);
    free(indPai2);
}

/*************************** AUX FUNCTIONS ******************************/

int calcular_nova_fobj(individuo solucao,
                       int PERIODOS,
                       int TERRENOS,
                       int *lucratividade_especies)
{
    int i, j, fobj = 0, last = 0;
    
    for (i = 0; i < TERRENOS; i++)
    {
        for (j = 0; j < PERIODOS; j++)
        {
            if (solucao.sol[i][j] != 0 && solucao.sol[i][j] != last)
            {
                last = solucao.sol[i][j];
                fobj += lucratividade_especies[solucao.sol[i][j] - 1];
            }
        }
        last = 0;
    }
    return fobj;
}
/**/
int comparar_indiv(const void *i,
                   const void *j)
{
    individuo *a,*b;
    a = (individuo *)i;
    b = (individuo *)j;
    if(a->f_obj > b->f_obj)    // decrescente
        return -1;
    else if(a->f_obj < b->f_obj)
        return 1;
    else
        return 0;
}
/**/
void copy_individuo(individuo from_ind,
                    individuo *to_ind,
                    int PERIODOS,
                    int TERRENOS)
{
    int i,j;
    
    (*to_ind).f_obj = from_ind.f_obj;
    
    for (i = 0; i< TERRENOS; i++)
    {
        for (j = 0; j < PERIODOS; j++)
        {
            (*to_ind).sol[i][j] = from_ind.sol[i][j];
        }
    }
}
/**/
void crossover(individuo pai1,
               individuo pai2,
               individuo *filho1,
               individuo *filho2,
               int PERIODOS,
               int TERRENOS,
               int *lucratividade_especies)
{
    int i, j;
    int division_line = (int)(TERRENOS * MAX_CROSSOVER_PERCENTAGE);
    
    for (i = 0; i < division_line; i++)
    {
        for (j = 0; j < PERIODOS; j++)
        {
            (*filho1).sol[i][j] = pai1.sol[i][j];
            (*filho2).sol[i][j] = pai2.sol[i][j];
        }
    }

    for (i = division_line; i < TERRENOS; i++)
    {
        for (j = 0; j < PERIODOS; j++)
        {
            (*filho1).sol[i][j] = pai1.sol[i][j];
            (*filho2).sol[i][j] = pai2.sol[i][j];
        }
    }
    
    calcular_nova_fobj((*filho1),PERIODOS,TERRENOS,lucratividade_especies);
    calcular_nova_fobj((*filho2),PERIODOS,TERRENOS,lucratividade_especies);

}
/**/
void gerar_conjunto_pais(individuo *populacao,
                         int *indPai1,
                         int *indPai2,
                         int QTDE)
{
    int i;
    
    for (i=0; i < QTDE; i++)
    {
        indPai1[i] = individuo_aleatorio(QTDE);
        indPai2[i] = individuo_aleatorio(QTDE);
        // caso primeiro pai igual ao segundo pai
        while (indPai1[i] == indPai2[i])
        {
            indPai2[i] = individuo_aleatorio(QTDE);
        }
    }
}
/**/
int individuo_aleatorio(int n)
{
    double aux;
    int i;
    
    // número aleatorio entre 0 e 1
    aux = uniforme(0,1);
    
    // i é inteiro entre 0 e n-1
    // ou seja, os índices do vetor selecionados
    i = (int)(1 + aux*n) - 1;
    return i;
}
/**/
int inteiro(int a,
            int b)
{
    double aux;
    int i;
    
    aux = uniforme(0,1);
    
    i = (int)(a + aux*(b - a));
    
    return i;
}
/**/
void make_new_population(individuo *new_population,
                         individuo *combined_group,
                         int POPULACAO)
{
    
    
    
}
/**/
void merge_populations(individuo *group_A,
                       individuo *group_B,
                       individuo *combined_group,
                       int PERIODOS,
                       int TERRENOS,
                       int POPULACAO)
{
    int i,k;
    for (i = 0; i < POPULACAO; i++)
    {
        copy_individuo(group_A[i], &combined_group[i], PERIODOS, TERRENOS);
    }
    for (i = 0, k = POPULACAO; i < POPULACAO; i++, k++)
    {
        copy_individuo(group_B[i], &combined_group[k], PERIODOS, TERRENOS);
    }
}
/**/
//void mutation()
//{
//
//}
/**/
void ordenar_populacao(individuo *populacao,
                       int POPULACAO)
{
    qsort(populacao,
          POPULACAO,
          sizeof(individuo),
          comparar_indiv);
}
/**/
individuo torneio(individuo pai1,
                  individuo pai2)
{
    int aux = pai1.f_obj - pai2.f_obj;
        
    if (aux < 0) //p1 < p2
    {
        return pai2;
    }
    else if (aux > 0) //p1 > p2
    {
        return pai1;
    }
    else
    {
        if (uniforme(0,1) <= 0.5)
        {
            return pai1;
        }
        else
        {
            return pai2;
        }
    }
}
/**/
double uniforme(double a, double b)
{
    double beta, aux;
    aux = (double)rand()/((double)RAND_MAX + 1);
    beta = a + aux*(b - a);
    return beta;
}
