void insertionSortOriginal(int *vet, int n){
    int i, j, aux;
    for(i = 1; i < n; i++){
        aux = vet[i];
        j = i;
        while(j > 0 && aux < vet[j-1]){
            vet[j] = vet[j-1];
            j--;
        }
        vet[j] = aux;
    }
}