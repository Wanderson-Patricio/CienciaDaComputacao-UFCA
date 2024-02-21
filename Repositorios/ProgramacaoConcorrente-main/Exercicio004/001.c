#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <locale.h>
#include "macro.h"

int main(){
    long number = 500000000;
    int numberOfThreads = 3;
    long soma = 0;
    double start, end;

    //Região sequencial
    start = omp_get_wtime();
    for(int i = 1; i<=number; i++){
        if(number % i == 0){
            soma += i;
        }
    }
    end = omp_get_wtime();
    double tempo_sequencial = end - start;
    printf("Soma na região sequencial: %ld\n", soma);

    //Região Paralela
    soma = 0;
    start = omp_get_wtime();
    #pragma omp parallel num_threads(numberOfThreads)
    {
        #pragma omp for reduction(+:soma)
        for(int i = 1; i<=number; i++){
            if(number % i == 0){
                soma += i;
            }
        }
    }
    end = omp_get_wtime();
    double tempo_paralelo = end - start;
    printf("Soma na região paralela: %ld\n", soma);

    //Região atomic
    soma = 0;
    start = omp_get_wtime();
    #pragma omp parallel num_threads(numberOfThreads)
    {
        long somar = 0;
        int thread = omp_get_thread_num();
        for(int i = thread; i<number; i += numberOfThreads){
            if(number % (i+1) == 0){
                somar += i + 1;
            }
        }

        #pragma omp atomic
        soma += somar;
    }
    end = omp_get_wtime();
    double tempo_atomic = end - start;
    printf("Soma na região atomic: %ld\n", soma);

    //Região critical
    soma = 0;
    start = omp_get_wtime();
    #pragma omp parallel num_threads(numberOfThreads)
    {
        long somar = 0;
        int thread = omp_get_thread_num();
        for(int i = thread; i<number; i += numberOfThreads){
            if(number % (i+1) == 0){
                somar += (i+1);
            }
        }

        #pragma omp atomic
        soma += somar;
    }
    end = omp_get_wtime();
    double tempo_critical = end - start;
    printf("Soma na região critical: %ld\n", soma);
    

    printInfo(tempo_sequencial, tempo_paralelo, numberOfThreads);
    printf("Tempo atomic:\t\t%.5f s\n", tempo_atomic);
    printf("Tempo critical:\t\t%.5f s\n", tempo_critical);



    return 0;
}
