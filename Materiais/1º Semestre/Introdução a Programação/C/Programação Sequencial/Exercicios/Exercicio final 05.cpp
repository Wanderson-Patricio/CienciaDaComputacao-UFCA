#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int a, b, desconto, valor;
	printf("Qual � o pre�o da mercadoria (em R$)? \n");
	scanf("%d", &a);
	printf("Quanto ser� a porcentagem do desconto? \n");
	scanf("%d", &b);
	printf("O produto ter� um desconto de R$%.2f , e seu valor final ser� de R$%.2f . \n", (float) a*(b/100.0), a*(1-b/100.0));
	return 0; 
}
