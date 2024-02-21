#include <stdio.h>
#include <locale.h>
int main() {
	int i;
	char nome[5][50];
	for(i=0; i<5;i++){
		scanf("%s", &nome[i]);
	}
	for(i=0; i<5;i++){
		printf("\n%s \n", nome[i]);
	}
	return 0;
}
