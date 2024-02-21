#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int tam = 15;


typedef struct{
	int linha;
	int coluna;
}Position;

int** cria_tabuleiro(){
	int** tab = (int**)malloc(tam*sizeof(int*));
	for(int i=0; i<tam; i++){
		*(tab+i) = (int*)calloc(tam, sizeof(int));
	}
	return tab;
}

void imprime_tab(int** tab){
	for(int i=0; i<tam+2; i++){
		printf("--");
	}
	printf("\n");
	for(int i=0; i<tam; i++){
		printf("| ");
		for(int j=0; j<tam; j++){
			printf("%d ", *(*(tab+i)+j));
		}
		printf(" |");
		printf("\n");
	}
	for(int i=0; i<tam+2; i++){
		printf("--");
	}
	printf("\n");
}

Position posicao(){
	srand(time(NULL));
	int linha = rand() % (tam);
	int coluna = rand() % (tam);
	Position inicial={linha, coluna};
	return inicial;
}

void comida(int** tab){
	srand(time(NULL));
	int linha, coluna;
	do{
		linha = rand() % (tam);
		coluna = rand() % (tam);
	}while(*(*(tab+linha)+coluna)!=0);
	*(*(tab+linha)+coluna)=2;
}

Position* cobra(int** tab, int n){
	Position* cobrinha = (Position*)malloc(n*sizeof(Position));
	int index = 0;
	for(int i=0; i<tam; i++){
		for(int j=0; j<tam; j++){
			
		}
	}
}















void apagar(int** tab){
	free(tab);
	tab = NULL;
}
