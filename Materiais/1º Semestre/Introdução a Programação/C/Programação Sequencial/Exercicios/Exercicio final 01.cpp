#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int a, b, soma;
	printf("Digite o primeiro n�mero a ser somado. \n");
	scanf("%d", &a);
	printf("Digite o segundo n�mero a ser somado . \n");
	scanf("%d", &b);
	soma = a+b;
	printf("A soma dos dois n�meros � igual a: %d. \n", soma);
	return 0;
}
