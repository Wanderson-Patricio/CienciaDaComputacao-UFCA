#include <stdio.h>

void printInfo(double tempo_sequencial, double tempo_paralelo, int numberOfThreads){
    double speedup = tempo_sequencial/tempo_paralelo;
    double efficiency = speedup/numberOfThreads;

    printf("Número de Threads:\t%d\n", numberOfThreads);
    printf("Tempo sequencial:\t%.5f s\n", tempo_sequencial);
    printf("Tempo paralelo:\t\t%.5f s\n", tempo_paralelo);
    printf("Speedup:\t\t%.5f\n", speedup);
    printf("Efficiency:\t\t%.5f\n", efficiency);
}
