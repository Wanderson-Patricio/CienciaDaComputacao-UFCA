#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i=1, numero, soma = 0;
	while(i<=10){
		printf("Digite um número:\n");
		scanf("%d", &numero);
		soma = soma + numero;
		i++;
	}
	printf("A soma dos números digitados é: %d", soma);
	return 0;
}
