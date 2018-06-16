int calcularNovaFObj(individuo solucao,
                     int PERIODOS,
                     int TERRENOS,
                     int *lucratividade_especies);

int compararIndiv(const void *i,
                  const void *j);

void copyIndividuo(individuo from_ind,
                   individuo *to_ind,
                   int PERIODOS,
                   int TERRENOS);

void crossover(individuo pai1,
               individuo pai2,
               individuo *filho1,
               individuo *filho2,
               int PERIODOS,
               int TERRENOS,
               int *lucratividade_especies);

void gerarConjuntoPais(individuo *populacao,
                       int *indPai1,
                       int *indPai2,
                       int QTDE);

int individuo_aleatorio(int n);

int inteiro(int a,
            int b);

void makeNewPopulation(individuo *new_population,
                       individuo *combined_group,
                       int POPULACAO,
                       int PERIODOS,
                       int TERRENOS);

void mergePopulations(individuo *group_A,
                      individuo *group_B,
                      individuo *combined_group,
                      int PERIODOS,
                      int TERRENOS,
                      int POPULACAO);

void mutation(individuo object,
              int ESPECIES,
              int PERIODOS,
              int TERRENOS,
              int PERIODOS_ANO,
              int *temp_proc,
              int **per_plantio,
              int *lucratividade_especies);

individuo torneio(individuo pai1,
                  individuo pai2);

double uniforme(double a,
                double b);
