#include <stdio.h>

int main(){
	int vet[] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29};
	int temp, tam = 15, inf = 0, sup = 14, meio, chave = 13;
	for(int i = 0; i < tam-1; i++){
		for(int j = i+1; j<tam; j++){
			if(vet[j]<vet[i]){
				temp = vet[j];
				vet[j] = vet[i];
				vet[i] = temp;
			}
		}
	}
	while(inf <= sup){
		meio = (inf + sup)/2;
		if(vet[meio] == chave){
			break;
		}else if(vet[meio] > chave){
			sup = meio - 1;
		}else{
			inf = meio + 1;
		}
	}
	printf("%d\n", meio);
	return 0;
}
