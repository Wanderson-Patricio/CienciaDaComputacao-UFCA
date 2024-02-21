#include <stdio.h>
#include <locale.h>
int main () {
	setlocale(LC_ALL, "portuguese");
	int n, i, j, k, m, l, p, q, passo=1;
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
	printf("\n");
	printf("Calculando o determinante pelo método de Gauus \n");
	for(i=0; i<n-1; i++){
		if(a[i][i]!=0){
			printf("\n");
			for(j=i+1; j<n; j++){
				mult=(a[j][i])/(a[i][i]);
				printf("Passo %d: Linha %d -> Linha %d - (%.2f)*Linha %d \n", passo, j+1, j+1, mult, i+1);
				passo++;
				for(k=0; k<n; k++){
					a[j][k]-=a[i][k]*mult;
				}
			}
			for(m=0; m<n; m++){
				printf("\n");
				for(l=0; l<n; l++){
					printf("%.2f  ", a[m][l]);
				}
			}
		}else{
			for(m=i; m<n; m++){
				if(a[m][i]!=0){
					printf("Passo %d: Linha %d -> Linha %d e Linha %d -> -Linha %d", passo, m+1, i+1, i+1, m+1);
					passo++;
					for(l=0; l<n; l++){
						aux=a[i][l];
						a[i][l]=-a[m][l];
						a[m][l]=aux;
					}
				}
			for(p=0; p<n; p++){
						printf("\n");
						for(q=0; q<n; q++){
							printf("%.2f  ", a[p][q]);
						}
					}
			break;	
			}
			printf("\n A matriz escalonada é: \n");
			for(p=0; p<n; p++){
				printf("\n");
				for(q=0; q<n; q++){
					printf("%.2f  ", a[p][q]);
				}
			}
			printf("\n O determinante da matriz é 0.");
			return 0;
				
		}
		for(j=i+1; j<n; j++){
			mult=(a[j][i])/(a[i][i]);
			printf("Passo %d: Linha %d -> Linha %d - %.2f*Linha %d \n", passo, j+1, j+1, mult, i+1);
			passo++;
			for(k=0; k<n; k++){
				a[j][k]-=a[i][k]*mult;
			}
		}
		for(m=0; m<n; m++){
			printf("\n");
			for(l=0; l<n; l++){
				printf("%.2f  ", a[m][l]);
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
