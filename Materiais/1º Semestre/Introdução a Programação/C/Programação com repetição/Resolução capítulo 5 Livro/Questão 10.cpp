#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, numero, soma=0;
	float media;
	for(i=1; i<=10; i++){
		printf("Digite um n�mero:\n");
		scanf("%d", &numero);
		while(!(numero>0)){
			printf("N�mero inv�lido. Digite novamente.\n");
			scanf("%d", &numero);
		}
		soma = soma + numero;
	}
	media= (float) soma/10;
	printf("A m�dia dos n�meros positivos digitados � %.2f", media);
	return 0;
}
