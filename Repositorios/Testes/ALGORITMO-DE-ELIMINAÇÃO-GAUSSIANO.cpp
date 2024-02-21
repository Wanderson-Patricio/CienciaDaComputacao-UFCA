#include <stdio.h>
#include <locale.h>



void preencher(float A[30][31], int n){
	int linhas = n;
	int colunas = n+1;
	
	for(int i = 0; i< linhas; i++){
		for(int j = 0; j< colunas; j++){
			printf("Digite A[%d][%d]: ", i, j);
			scanf("%f", &A[i][j]);
		}
	}
}


void imprime_sistema(float A[30][31], int n){
	int linhas = n;
	int colunas = n+1;
	
	for(int i = 0; i< linhas; i++){
		for(int j = 0; j < colunas; j++){
			if(j == colunas -2){
				
				printf("%.2f*x%d = ", A[i][j], i+1);
				
			}else if(j == colunas -1){
				
				printf("%.2f\n", A[i][j]);
				
			}else{
				if(*(*(A+i)+j+1) < 0){
					
					printf("%.2f*x%d - ", -A[i][j], i+1);
					
				}
				else{
					
					printf("%.2f*x%d + ", A[i][j], i+1);
					
				}
				
			}
		}
	}
}

void dividir_linha(float A[30][31], int n, int L){
	
	for(int i=0; i<n+1; i++){
		A[L][i] =  A[L][i]/A[L][L];	
	}
	
}

void atualizar_linhas(float A[30][31], int n, int C){
	int linhas = n;
	int colunas = n+1;
	
	float factor;
	
	dividir_linha(A, n, C);
	
	for(int i = 0; i<linhas; i++){
		
		if(i != C){
			factor = A[i][C]/A[C][C];
		
			for(int j = 0; j< colunas+1; j++){
			
				A[i][j] = A[i][j] - factor*A[C][j];
			
			}
		}
	}
	
}

void resolve_sistema(float A[30][31], int n){
	for(int i = 0; i < n; i++){
		
		atualizar_linhas(A, n, i);
		
	}
	
	printf("A solução do sistema é: \n");
	
	for(int i=0; i< n; i++){
		printf("X%d = %.2f \n", i+1, A[i][n]);
	}
	
}

int main(){
	setlocale(LC_ALL, "portuguese");
	
	int n;
	
	do{
		printf("Número de equações do sistema (digite um valor inteiro entre 2 e 30): ");
		scanf("%d", &n);
	}while(n < 2 || n > 30);
	
	float A[30][31];
	
	preencher(A, n);
	imprime_sistema(A, n);
	resolve_sistema(A, n);
	
	return 0;
}





