#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, a[6];
	for(i=0; i<6; i++){
		printf("Digite um número:");
		scanf("%d", &a[i]);
	}
	for(i=0; i<6; i++){
		printf("%d \n", a[5-i]);
	}
	return 0;
}
