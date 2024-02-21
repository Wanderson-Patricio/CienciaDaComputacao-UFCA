#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int a, aumento;
	a = 1500;
	aumento = 1.1*a;
	printf("O aumento ajustado para um salário de R$%.2f é: R$%.2f", (float) a, (float) aumento);
	return 0; 
}
