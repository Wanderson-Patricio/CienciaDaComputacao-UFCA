#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int a;
	printf("Digite um número inteiro. \n");
	scanf("%d", &a);
	printf("Número digitado: %d \n", a);
	return 0;
}
