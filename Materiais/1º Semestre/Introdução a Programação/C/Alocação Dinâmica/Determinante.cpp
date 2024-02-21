#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//Cria uma matriz na memória heap
float** criaMatriz(int linhas, int colunas){
	float** temp = (float**)malloc(linhas*sizeof(float*));
	for(int i=0; i<linhas; i++){
		*(temp+i) = (float*)malloc(colunas*sizeof(float));
	}
	return temp;
}

//Imprime a matriz na tela
void printMat(float** mat, int linhas, int colunas){
	for(int i=0; i<linhas; i++){
		for(int j=0; j<colunas; j++){
			printf("%.2f ", *(*(mat+i)+j));
		}
		printf("\n");
	}
}

//Preenche a matriz com valores aleatórios entre 1 e 100
void fillMat(float** mat, int linhas, int colunas){
	srand(time(NULL));
	for(int i=0; i<linhas; i++){
		for(int j=0; j<colunas; j++){
			*(*(mat+i)+j) = (float) (rand()%3 + 1);
		}
	}
}

//Libera a matriz da heap
void liberar(float** mat){
	free(mat);
	mat=NULL;
}

//Verifica se existe alguma linha com um elemento não nulo
int encontraLinha(float** mat, int linha_inicial, int tam){
	for(int i=linha_inicial+1; i<tam;i++){
		if(*(*(mat+i)+linha_inicial)!=0){
			return i;
		}
	}
	return 0;
}

//Troca dois elementos
void swap(float* a, float* b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

//Troca duas linhas de um vetor
void trocaLinha(float** mat, int linha1, int linha2, int tam){
	for(int j=0; j<tam; j++){
		swap(*(mat+linha1)+j,*(mat+linha2)+j);
	}
}

//Identifica qual o coeficiente de multiplicação
float mult(float a, float b){
	float result = a/b;
	return result;
}

//Escalona uma linha
void escalonaLinha(float** mat, int linha1, int linha2, int tam){
	float multiplier=mult(*(*(mat+linha2)+linha1),*(*(mat+linha1)+linha1));
	for(int j=linha1; j<tam; j++){
		*(*(mat+linha2)+j)-=multiplier*mat[linha1][j];
	}
}

//Multiplica os elementos da diagonal principal
float multDiagonal(float** mat, int tam){
	float result = 1;
	for(int i=0; i<tam;i++){
		result*=mat[i][i];
	}
	return result;
}

//Calcula o determinante
float determinante(float** mat, int tam){
	float det=-1, linha;
	float result;
	for(int i=0; i<tam-1; i++){
		if(mat[i][i]!=0){
			for(int k=i+1; k<tam; k++){
				escalonaLinha(mat, i, k, tam);
			}
		}else{
			linha=encontraLinha(mat, i,tam);
			if(linha==0){
				det = 0;
				break;
			}else{
				trocaLinha(mat, i, linha, tam);
				for(int k=i+1; k<tam; k++){
					escalonaLinha(mat, i, k, tam);
				}
			}
		}
	}
	if(det!=0){
		det = multDiagonal(mat, tam);
	}
	return det;
}


int main(){
	int dimensao=10;
	float **mat=criaMatriz(dimensao, dimensao);
	/*for(int i=0;i<dimensao;i++){
		for(int j=0; j<dimensao;j++){
			scanf("%f", *(mat+i)+j);
		}
	}*/
	fillMat(mat,dimensao,dimensao);
	printMat(mat,dimensao,dimensao);
	printf("\n Determinante: %.2f\n", determinante(mat, dimensao));
	liberar(mat);
	return 0;
}
