#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int a, b, desconto, valor;
	printf("Qual é o preço da mercadoria (em R$)? \n");
	scanf("%d", &a);
	printf("Quanto será a porcentagem do desconto? \n");
	scanf("%d", &b);
	printf("O produto terá um desconto de R$%.2f , e seu valor final será de R$%.2f . \n", (float) a*(b/100.0), a*(1-b/100.0));
	return 0; 
}
