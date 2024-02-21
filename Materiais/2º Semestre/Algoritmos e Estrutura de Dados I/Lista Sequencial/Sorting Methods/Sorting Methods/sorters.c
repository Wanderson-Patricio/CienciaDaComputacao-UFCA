#include <stdlib.h>
#include <stdio.h>
#include "sorters.h"
#include <time.h>

int* criaVet(int n){
    srand(time(NULL));
    int* a = (int*)malloc(n*sizeof(int));
    for(int i = 0; i<n; i++){
        *(a+i) = rand()%100 + 1;
    }
    return a;
}

void imprimeVet(int* vet, int n){
    for(int i = 0; i<n; i++){
        if(i==0){
            printf("(%d, ", *(vet+i));
        }else if(i==n-1){
            printf("%d) \n\n", *(vet+i));
        }else{
            printf("%d, ", *(vet+i));
        }
    }
}

void apagaVet(int* vet){
    free(vet);
    vet = NULL;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* vet, int n){
    for(int i = n-1; i>0; i--){
        for(int j = 0; j<i; j++){
            if(*(vet+j)>*(vet+j+1)){
                swap((vet+j),(vet+j+1));
            }
        }
    }
}

void selectionSort(int* vet, int n){
    int menor;
    for(int i = 0; i<n-1; i++){
        menor = i;
        for(int j=i+1; j<n; j++){
            if(vet[j]<vet[menor]){
                menor = j;
            }
        }
        swap((vet+i),(vet+menor));
    }
}

void Merge(int* vet, int inf, int sup, int mid){
    int esq = inf;
    int dir = mid;
    int tam = sup-inf;
    int* aux = (int*)malloc(tam*sizeof(int));
    for(int k = 0; k< tam; k++){
        int temp;
        if(esq >=mid){
            temp = *(vet+dir);
            dir++;
        }else if(dir>=sup){
            temp = *(vet + esq);
            esq ++;
        }else{
            if(*(vet+esq)<=*(vet+dir)){
                temp = *(vet + esq);
                esq ++;
            }else{
                temp = *(vet+dir);
                dir++;
            }
        }
        *(aux+k) = temp;
    }

    for(int k = 0; k<tam; k++){
        *(vet + inf + k) = *(aux+k);
    }
}

void mergeSort(int* vet, int inf, int sup){
    int mid = (inf+sup)/2;
    if(inf<sup-1){
        mergeSort(vet, inf, mid);
        mergeSort(vet, mid, sup);
    }
    Merge(vet, inf, sup, mid);
}

int particao(int* vet, int inf, int sup, int pivot){
    int tam = sup-inf+1;

    int* vetEsq = (int*)malloc(tam*sizeof(int));
    int indexEsq = 0;
    int* vetDir = (int*)malloc(tam*sizeof(int));
    int indexDir = 0;

    swap((vet+pivot),(vet+sup));

    for(int k = inf; k<=sup-1; k++){
        if(*(vet+k)<=*(vet+sup)){
            *(vetEsq+indexEsq) = *(vet+k);
            indexEsq++;
        }else{
            *(vetDir+indexDir) = *(vet+k);
            indexDir++;
        }
    }

    *(vetEsq+indexEsq) = *(vet+sup);
    indexEsq++;

    for(int k = 0; k<indexEsq; k++){
        *(vet+inf+k) = *(vetEsq + k);
    }

    for(int k = 0; k<indexDir; k++){
        *(vet+inf+indexEsq+k) = *(vetDir+k);
    }

    return inf+indexEsq-1;
}

void quickSort(int* vet, int inf, int sup){
    int pivot = (inf+sup)/2;
    if(inf<sup){
        int position = particao(vet, inf, sup, pivot);
        quickSort(vet, inf, position-1);
        quickSort(vet, position+1, sup);
    }
}

