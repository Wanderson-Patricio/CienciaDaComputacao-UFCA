#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>



int main(){
	setlocale(LC_ALL, "portuguese");
	int vet[5] = {1,2,3,4,5};
	int *pont = vet;
	for(int i=0; i<5; i++){
		printf("%d\n", 2*(*(pont+i)));
	}
	return 0;
}
