// Algoritmo de Busca Binária

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Função para preencher um um vetor com valores aleatórios entre 1 e tam
void preencheVetor(int *vet, int tam){
	srand(time(NULL));
	for(int i = 0; i < tam; i++){
		*(vet + i) = (rand()%tam)+ 1;
	}
}

// Função para criar um vetor na memória heap preenchida com valores aleatórios entre 1 e tam
int* criaVet(int n){
	int* vet = (int*)malloc(n*sizeof(int));
	preencheVetor(vet, n);
	return vet;
}

// Função para imprimir um vetor de tamanho tam
void printVet(int *vet, int tam){
	for(int i = 0; i < tam; i++){
		if(i == tam - 1){
			printf("%d\n", *(vet+i));
		}else{
			printf("%d, ", *(vet+i));
		}
	}
}

// Ordenação de Bubble Sort (complexidade O(n²))
void BubbleSort(int *vet, int tam){
	int temp;
	for(int i = 0; i < tam-1; i++){
		for(int j = i+1; j<tam; j++){
			if(*(vet+j)<*(vet+i)){
				temp = vet[j];
				vet[j] = vet[i];
				vet[i] = temp;
			}
		}
	}
}

// Função Merge (intercalação das duas sublistas ordenadas)
void Merge(int *vet, int inicio,int meio, int fim){
	int tamEsq = meio - inicio + 1;
	int tamDir = fim - meio;
	int vetEsq[tamEsq], vetDir[tamDir];
	for(int i = 0; i<tamEsq; i++){
		vetEsq[i] = vet[inicio + i];
	}
	for(int i = 0; i<tamDir; i++){
		vetDir[i] = vet[meio + i + 1];
	}
	int indexEsq = 0, indexDir = 0;
	for(int i = inicio; i<=fim; i++){
		if(indexEsq < tamEsq){
			if(indexDir < tamDir){
				if(vetEsq[indexEsq]<vetDir[indexDir]){
					vet[i] = vetEsq[indexEsq];
					indexEsq++;
				}else{
					vet[i] = vetDir[indexDir];
					indexDir++;
				}
			}else{
				vet[i] = vetEsq[indexEsq];
				indexEsq++;
			}
		}else{
			vet[i] = vetDir[indexDir];
			indexDir++;
		}
	}
}

// Ordenação de Merge Sort (complexidade O(n.log n))
void MergeSort(int *vet,int inicio, int fim){
	int meio;
	if(inicio < fim){
		meio = (inicio + fim)/2;
		MergeSort(vet, inicio, meio);
		MergeSort(vet,meio+1, fim);
		Merge(vet, inicio, meio, fim);
	}
}

// Ordenação de Quick Sort
void QuickSort(int *vet, int inicio, int fim){
	int i = inicio, j = fim, aux, pivo;
	int meio = (i+j)/2;
	pivo = vet[meio];
	while(i<=j){
		while(vet[i] < pivo){
			i++;
		}
		while(vet[j] > pivo){
			j--;
		}
		if(i<=j){
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			i++;
			j--;
		}
	}
	if(inicio < j){
		QuickSort(vet, inicio, j);
	}
	if(i < fim){
		QuickSort(vet, i, fim);
	}
}

// Busca binária sobre um vetor ordenado
int binarySearch(int *vet, int tam, int chave){
	int inf = 0, sup = tam - 1, meio;
	while(inf <= sup){
		meio = (inf + sup)/2;
		if(vet[meio] == chave){
			return meio;
		}else if(vet[meio] > chave){
			sup = meio - 1;
		}else{
			inf = meio + 1;
		}
	}
	return -1;
}

// Função para liberar o espaço na memória heap
void liberaVet(int *vet){
	free(vet);
	vet = NULL;
}

// Função Main
int main(){
	setlocale(LC_ALL, "portuguese");
	int  verifier = 1, position, option, chave, tam;
	int *vet = NULL;
	while(verifier == 1){
		system("cls");
		printf("O que você deseja fazer?\n 1 - Criar novo vetor\n 2 - Imprimir o vetor na tela\n 3 - Ordenar o vetor criado (Bubble Sort)\n 4 - Ordenar o vetor criado (Merge Sort)\n 5 - Ordenar o vetor criado (Quick Sort)\n 6 - Buscar elemento no vetor\n 7 - Sair do programa\n");
		scanf("%d", &option);
		system("cls");
		switch(option){
			case 1:{
				printf("Qual tamanho do vetor?\n");
				scanf("%d", &tam);
				liberaVet(vet);
				vet = criaVet(tam);
				system("cls");
				printf("O vetor foi criado.\n");
				system("pause");
				break;
			}
			case 2:{
				printVet(vet, tam);
				system("pause");
				break;
			}
			case 3:{
				printf("O vetor está sendo ordenado. Aguarde alguns instantes.\n");
				BubbleSort(vet, tam);
				system("cls");
				printf("O vetor foi ordenado.\n");
				system("pause");
				break;
			}
			case 4:{
				printf("O vetor está sendo ordenado. Aguarde alguns instantes.\n");
				MergeSort(vet, 0, tam-1);
				system("cls");
				printf("O vetor foi ordenado.\n");
				system("pause");
				break;
			}
			case 5:{
				printf("O vetor está sendo ordenado. Aguarde alguns instantes.\n");
				QuickSort(vet, 0, tam-1);
				system("cls");
				printf("O vetor foi ordenado.\n");
				system("pause");
				break;
			}
			case 6:{
				printf("Qual o elemento que você deseja buscar?\n");
				scanf("%d", &chave);
				position = binarySearch(vet, tam, chave);
				if(position == -1){
					printf("O elemento %d não está no vetor.\n", chave);
				}else{
					printf("O elemento %d está na posição %d.\n", chave, position + 1);
				}
				system("pause");
				break;
			}
			case 7:{
				verifier = 0;
				break;
			}
		}
	}
	liberaVet(vet);
	printf("Obrigado por usar o nosso programa :):)\n");
	return 0;
}
