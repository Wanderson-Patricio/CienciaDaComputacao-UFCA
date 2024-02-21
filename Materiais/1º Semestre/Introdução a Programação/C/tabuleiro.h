#include <stdio.h>
#include <stdlib.h>

int cond_vit(int acertos){
	int result = 0;
	if(acertos == 5){
		result = 1;
	}
	return result;
}

int** cria_tabuleiro(){
	int** tab = (int**)malloc(5*sizeof(int*));
	for(int i=0; i<5; i++){
		*(tab + i) = (int*)malloc(5*sizeof(int));
	}
	return tab;
}

void preenche_tabuleiro(int** tabuleiro, int num){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			*(*(tabuleiro + i) +j) = num;
		}
	}
}

void imprime(int** tabuleiro){
	for(int i=0; i<7; i++){
		if(i == 0){
			for(int j=0; j<6; j++){
				switch(j){
					case 0: printf(" | "); break;
					case 1: printf("a  "); break;
					case 2: printf("b  "); break;
					case 3: printf("c  "); break;
					case 4: printf("d  "); break;
					case 5: printf("e  "); break;
				}
			}
		}else if(i == 1){
			for(int j=0; j<6; j++){
				if(j == 5){
					printf("-");
				}else{
					printf("---");
				}
			}
		}else{
			for(int j=0; j<6; j++){
				if(j == 0){
					printf("%d| ", i-1);
				}else{
					printf("%d  ", tabuleiro[i-2][j-1]);
				}
			}
		}
		printf("\n");
	}
	printf("\n");
}

void apagar(int** tabuleiro){
	free(tabuleiro);
	tabuleiro = NULL;
}
