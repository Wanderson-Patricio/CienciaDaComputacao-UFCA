#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int a, b, resultado;
	printf("Quanto é o seu salário atual (em R$)? \n");
	scanf("%d", &a);
	printf("Qual será a porcentagem de aumento? \n");
	scanf("%d", &b);
	resultado = a*(1+b/100.0);
	printf("O seu salário após o aumento será: R$ %.2f \n", (float) resultado);
	return 0;
}
