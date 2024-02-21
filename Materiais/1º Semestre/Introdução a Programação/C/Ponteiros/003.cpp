#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "portuguese");
	float vet[10] = {1,2,3,4,5,6,7,8,9,10};
	int *pont = (int*)vet;
	for(int i=0; i<10; i++){
		printf("O endereco de %.2f é %d.\n", vet[i], (pont+i));
	}
	return 0;
}
