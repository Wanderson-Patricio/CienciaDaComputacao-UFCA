#include <stdio.h>
#include <locale.h>
int main () {
	setlocale(LC_ALL, "portuguese");
	int n, i, j, k, m, l;
	printf("Qual a ordem da matriz? \n");
	scanf("%d", &n);
	float a[n][n], mult, aux, det=1;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("Digite a[%d][%d]: ", i, j);
			scanf("%f", &a[i][j]);
		}
	}
	printf("A matriz digitada foi: \n");
	for(i=0; i<n; i++){
		printf("\n");
		for(j=0; j<n; j++){
			printf("%.2f  ", a[i][j]);
		}
	}
	for(i=0; i<n-1; i++){
		if(a[i][i]!=0){
			printf("\n");
			for(j=i+1; j<n; j++){
				mult=(a[j][i])/(a[i][i]);
				for(k=0; k<n; k++){
					a[j][k]-=a[i][k]*mult;
				}
			}
		}else{
			for(m=i; m<n; m++){
				if(a[m][i]!=0){
					for(l=0; l<n; l++){
						aux=a[i][l];
						a[i][l]=-a[m][l];
						a[m][l]=aux;
					}
					break;
				}else{
					printf("\n A matriz escalonada é: \n");
					for(m=0; m<n; m++){
						printf("\n");
						for(l=0; l<n; l++){
							printf("%.2f  ", a[m][l]);
						}
					}
					return 0;
				}
			}
			for(j=i+1; j<n; j++){
				mult=(a[j][i])/(a[i][i]);
				for(k=0; k<n; k++){
					a[j][k]-=a[i][k]*mult;
				}
			}
		}
	}
	printf("\n");
	printf("A matriz Equivalente após o escalonamento é: \n");
	for(i=0; i<n; i++){
		printf("\n");
		for(j=0; j<n; j++){
			printf("%.2f  ", a[i][j]);
		}
	}
	for(i=0; i<n; i++){
		det*=a[i][i];
	}
	printf("\n");
	printf("O determinante da matriz digitada é: %.2f.", det);
	return 0;
}
