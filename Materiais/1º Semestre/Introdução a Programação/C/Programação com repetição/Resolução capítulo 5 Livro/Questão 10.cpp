#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, numero, soma=0;
	float media;
	for(i=1; i<=10; i++){
		printf("Digite um número:\n");
		scanf("%d", &numero);
		while(!(numero>0)){
			printf("Número inválido. Digite novamente.\n");
			scanf("%d", &numero);
		}
		soma = soma + numero;
	}
	media= (float) soma/10;
	printf("A média dos números positivos digitados é %.2f", media);
	return 0;
}
