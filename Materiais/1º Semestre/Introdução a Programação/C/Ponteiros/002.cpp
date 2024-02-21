#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

void maior_endereco(int *a, int *b){
	if(a>b){
		printf("\n%d é maior.\n", *a);
	}else{
		printf("\n%d é maior.\n", *b);
	}
}

int main(){
	setlocale(LC_ALL, "portuguese");
	int a = 15, b = 0;
	printf("%d\t%d", &a, &b);
	maior_endereco(&a, &b);
	return 0;
}
