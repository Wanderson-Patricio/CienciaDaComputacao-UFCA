#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i=1, numero, soma = 0;
	float media;
	while(i<=10){
		printf("Digite um n�mero:\n");
		scanf("%d", &numero);
		soma = soma + numero;
		i++;
	}
	media = (float) soma/10;
	printf("A m�dia dos n�meros digitados �: %.2f", media);
	return 0;
}
