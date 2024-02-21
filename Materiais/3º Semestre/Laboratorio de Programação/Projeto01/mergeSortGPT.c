void mergeGPT(int* vet, int inicio, int meio, int fim) {
    int tamanho = fim - inicio + 1;
    int* temp = (int*)malloc(tamanho * sizeof(int));
    if (temp != NULL) {
        int p1 = inicio;
        int p2 = meio + 1;
        for (int i = 0; i < tamanho; i++) {
            if (p1 <= meio && (p2 > fim || vet[p1] <= vet[p2])) {
                temp[i] = vet[p1];
                p1++;
            } else {
                temp[i] = vet[p2];
                p2++;
            }
        }
        for (int j = 0, k = inicio; j < tamanho; j++, k++) {
            vet[k] = temp[j];
        }
        free(temp);
    }
}

void mergeSortGPT(int* vet, int inicio, int fim) {
    if (inicio < fim) {
        if (fim - inicio < 5) {
            // Use insertion sort for small arrays
            for (int i = inicio; i <= fim; i++) {
                int key = vet[i];
                int j = i - 1;
                while (j >= inicio && vet[j] > key) {
                    vet[j + 1] = vet[j];
                    j--;
                }
                vet[j + 1] = key;
            }
        } else {
            int meio = inicio + (fim - inicio) / 2;
            mergeSortGPT(vet, inicio, meio);
            mergeSortGPT(vet, meio + 1, fim);
            mergeGPT(vet, inicio, meio, fim);
        }
    }
}