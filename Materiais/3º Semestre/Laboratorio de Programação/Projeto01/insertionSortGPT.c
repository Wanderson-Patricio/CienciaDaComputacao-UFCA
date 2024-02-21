void insertionSortGPT(int *vet, int n) {
    for (int i = 1; i < n; i++) {
        int temp = vet[i];
        int low = 0, high = i - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (temp < vet[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        for (int j = i; j > low; j--) {
            vet[j] = vet[j - 1];
        }
        vet[low] = temp;
    }
}