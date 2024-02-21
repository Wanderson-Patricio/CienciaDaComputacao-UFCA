#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, a[3];
	printf("Digite um número de três dígitos: \n");
	for(i=0; i<=2; i++){
		scanf("%d", &a[i]);
	}
	for(i=2; i>=0; i--){
		printf("%d", a[i]);
	}
	return 0;
}
