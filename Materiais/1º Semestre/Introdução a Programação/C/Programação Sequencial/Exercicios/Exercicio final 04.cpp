#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int a, b, resultado;
	printf("Quanto � o seu sal�rio atual (em R$)? \n");
	scanf("%d", &a);
	printf("Qual ser� a porcentagem de aumento? \n");
	scanf("%d", &b);
	resultado = a*(1+b/100.0);
	printf("O seu sal�rio ap�s o aumento ser�: R$ %.2f \n", (float) resultado);
	return 0;
}
