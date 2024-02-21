#include <stdio.h>
#include <locale.h>
int main () {
	setlocale(LC_ALL, "portuguese");
	int n;
	printf("Qual a ordem da sua matriz? \n");
	scanf("%d", &n);
	int i, j, k, a[n][n], b[n][n];
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("Digite a[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			b[i][j]=0;
			for(k=0; k<n; k++){
				b[i][j]+=a[i][k]*a[k][j];
			}
		}
	}
	printf("\n A=");
	for(i=0; i<n; i++){
		printf("\n");
		for(j=0; j<n; j++){
			printf("%d  ", a[i][j]);
		}
	}
	printf("\n A^2=");
	for(i=0; i<n; i++){
		printf("\n");
		for(j=0; j<n; j++){
			printf("%d  ", b[i][j]);
		}
	}
}
