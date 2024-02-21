#ifndef SORTERS_H_INCLUDED
#define SORTERS_H_INCLUDED

int* criaVet(int n);
void imprimeVet(int* vet, int n);
void apagaVet(int* vet);

void bubbleSort(int* vet, int n);
void selectionSort(int* vet, int n);

void Merge(int* vet, int inf, int sup, int mid);
void mergeSort(int* vet, int inf, int sup);

int particao(int* vet, int inf, int sup, int pivot);
void quickSort(int* vet, int inf, int sup);

#endif // SORTERS_H_INCLUDED
