#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "sorters.h"

int main(){
    setlocale(LC_ALL, "portuguese");
    int n = 500;
    int* vet = (int*)malloc(n*sizeof(int));

    printf("Ordenação por Bubble Sort.\n");
    vet = criaVet(n);
    imprimeVet(vet, n);
    bubbleSort(vet, n);
    imprimeVet(vet, n);
    apagaVet(vet);
    system("pause");
    system("cls");

    printf("Ordenação por Selection Sort.\n");
    vet = criaVet(n);
    imprimeVet(vet, n);
    selectionSort(vet, n);
    imprimeVet(vet, n);
    apagaVet(vet);
    system("pause");
    system("cls");

    printf("Ordenação por Merge Sort.\n");
    vet = criaVet(n);
    imprimeVet(vet, n);
    mergeSort(vet, 0, n);
    imprimeVet(vet, n);
    apagaVet(vet);
    system("pause");
    system("cls");

    printf("Ordenação por Quick Sort.\n");
    vet = criaVet(n);
    imprimeVet(vet, n);
    quickSort(vet, 0, n-1);
    imprimeVet(vet, n);
    apagaVet(vet);

    return 0;
}
