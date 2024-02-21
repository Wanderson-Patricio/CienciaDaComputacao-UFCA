#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

void size(){
	printf("Tamanho de interiro: %d\n", sizeof(int));
	printf("Tamanho de char: %d\n", 4*sizeof(char));
	printf("Tamanho de float: %d\n", sizeof(float));
	printf("Tamanho de double: %d\n", sizeof(double));
}

int main(){
	setlocale(LC_ALL, "portuguese");
	size();
	return 0;
}
