#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int n;
	printf("Qual a ordem da matriz identidade? \n");
	scanf("%d", &n);
	int mat[n][n], i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i==j){
				mat[i][j]=1;
			}else{
				mat[i][j]=0;
			}
		}
	}
	printf("A matriz identidade de ordem %d é: \n", n);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}
