#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i=1, numero, soma = 0;
	while(i<=10){
		printf("Digite um n�mero:\n");
		scanf("%d", &numero);
		soma = soma + numero;
		i++;
	}
	printf("A soma dos n�meros digitados �: %d", soma);
	return 0;
}
