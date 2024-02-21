#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int a, b, soma;
	a = 3;
	b = 5;
	soma = 2*a+3*b;
	printf("O resultado da operação 2a+3b é: %d \n", soma);
	return 0;
}
