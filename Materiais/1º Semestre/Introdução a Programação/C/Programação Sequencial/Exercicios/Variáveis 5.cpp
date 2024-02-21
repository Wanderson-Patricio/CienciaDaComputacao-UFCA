#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int a, b;
	a=45;
	b=34;
	printf("soma: %d \n", a+b);
	printf("subtração: %d \n", a-b);
	printf("Multiplicação: %d \n", a*b);
	printf("Divisão: %.2f \n", (float) a/b);
	return 0;
}
