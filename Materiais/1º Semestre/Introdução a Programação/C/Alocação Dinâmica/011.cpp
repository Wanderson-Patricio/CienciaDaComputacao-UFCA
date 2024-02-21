#include <stdio.h>
#include <stdlib.h>

int** matriz(int n){
	int** mat = (int**)malloc(n*sizeof(int*));
	for(int i=0; i<n; i++){
		*(mat+i) = (int*)calloc(n, sizeof(int));
		*(*(mat+i)+i) = 1;
	}
	return mat;
}

int main(){
	int n = 10;
	int** mat = matriz(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
