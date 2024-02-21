#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <locale.h>
#include "macro.h"


#define MAX 100
#define TAMANHO 1000000000
#define VALOR_PROCURADO 55

int *gerar_vetor(int n) {
    int *vetor;
    int i;
    vetor = (int *)malloc(sizeof(int) * n);
    for (i=0;i<n;i++) {
        int num = (rand() % MAX);
        vetor[i] = num;
    }
    return vetor;
}

int main(){
    srand(time(NULL));
    int count_seq = 0, count_parallel = 0, count_critical = 0;
    int number_of_threads = 3;
    double start, end, seq_time, parallel_time;
    int* vet = gerar_vetor(TAMANHO);

    //Região sequencial
    start = omp_get_wtime();
    for(int i = 0; i<TAMANHO; i++){
        if(vet[i] == VALOR_PROCURADO){
            count_seq += 1;
        }
    }
    end = omp_get_wtime();
    seq_time = end - start;

    //Região paralela
    start = omp_get_wtime();
    #pragma omp parallel num_threads(number_of_threads)
    {
        #pragma omp for reduction (+: count_parallel)
        for(int i = 0; i<TAMANHO; i++){
            if(vet[i] == VALOR_PROCURADO){
                count_parallel += 1;
            }
        }
    }
    end = omp_get_wtime();
    parallel_time = end - start;

    //Região atomic
    start = omp_get_wtime();
    #pragma omp parallel num_threads(number_of_threads)
    {
        long somar = 0;
        int thread = omp_get_thread_num();
        for(int i = thread; i<TAMANHO; i += number_of_threads){
            if(vet[i] == VALOR_PROCURADO){
                somar += 1;
            }
        }

        #pragma omp critical
        count_critical += somar;
    }
    end = omp_get_wtime();
    double tempo_critical = end - start;

    printInfo(seq_time, parallel_time, &tempo_critical, number_of_threads);

    return 0;
}
