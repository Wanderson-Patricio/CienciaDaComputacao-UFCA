#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int a;
	printf("Digite um n�mero inteiro. \n");
	scanf("%d", &a);
	printf("N�mero digitado: %d \n", a);
	return 0;
}
