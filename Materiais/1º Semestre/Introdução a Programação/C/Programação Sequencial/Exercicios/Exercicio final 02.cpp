#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int a, soma;
	printf("Digite a dist�ncia a ser convertida. \n");
	scanf("%d", &a);
	soma = 1000*a;
	printf("%d m � igual a %d mm. \n", a, soma);
	return 0;
}
