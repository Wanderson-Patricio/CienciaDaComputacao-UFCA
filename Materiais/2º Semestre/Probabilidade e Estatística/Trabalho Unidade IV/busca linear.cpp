#include <stdio.h>
#include <stdlib.h>

void buscaLista(int n){
	int* li = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++){
		*(li + i) = i;
	}
	
	int soma = 0;
	
	for(int i=0; i<n; i++){
		soma += (*(li+i))*(*(li+i));
	}
	
	printf("Busca realizada com sucesso.\n");
}

int main(){
	int n =        2000000        ;
	buscaLista(n);
}
