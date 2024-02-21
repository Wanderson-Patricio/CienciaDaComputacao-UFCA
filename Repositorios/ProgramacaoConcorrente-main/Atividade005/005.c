#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <locale.h>
#include "macro.h"


#define MAX 100
#define TAMANHO 1000000

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
    int maior;
    int count_seq = 0, count_parallel = 0, count_critical = 0;
    int number_of_threads = 3;
    double start, end, seq_time, parallel_time;
    int* vet = gerar_vetor(TAMANHO);

    //Região sequencial
    start = omp_get_wtime();
    maior = vet[0];
    for(int i = 0; i<TAMANHO; i++){
        if(vet[i] > maior){
            maior = vet[i];
        }
    }
    end = omp_get_wtime();
    seq_time = end - start;

    printf("Sequencial: \t\t%d\n", maior);

    //Região paralela
    start = omp_get_wtime();
    #pragma omp parallel num_threads(number_of_threads)
    {
        int Greater = 0;
        #pragma omp for
        for(int i = 0; i<TAMANHO; i++){
            if(vet[i] > vet[Greater]){
                Greater = i;
            }
        }
        maior = Greater;
    }
    
    end = omp_get_wtime();
    parallel_time = end - start;
    printf("Paralelo: \t\t%d\n", maior);

    //Região Critical
    start = omp_get_wtime();
    int greater[number_of_threads];
    #pragma omp parallel num_threads(number_of_threads)
    {
        
        int thread = omp_get_thread_num();
        int largest = greater[thread];
        for(int i = thread; i<TAMANHO; i += number_of_threads){
            if(vet[i] > largest){
                largest = vet[i];
            }
        }
        #pragma omp critical
        greater[thread] = largest;
    }

    maior = greater[0];
    for(int i = 0; i<number_of_threads; i++){
        if(greater[i] > maior){
            maior = greater[i];
        }
    }

    end = omp_get_wtime();
    double tempo_critical = end - start;
    printf("Critical: \t\t%d\n", maior);

    printInfo(seq_time, parallel_time, &tempo_critical, number_of_threads);

    return 0;
}
