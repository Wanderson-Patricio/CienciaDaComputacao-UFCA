#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i = 1, n, numero, maior, contador =1;
	printf("Quantos números serão digitados: \n");
	scanf("%d", &n);
	printf("Digite um número: \n");
	scanf("%d", &numero);
	maior = numero;
	if(n==1){
		printf("O maior número digitado é %d. Ele apareceu 1 vez.", maior);
		return 0;
	}
	while(i<=n-1){
		printf("Digite um número: \n");
		scanf("%d", &numero);
		if(numero>maior){
			contador = 1;
			maior = numero;
		}else if(numero==maior){
			contador = contador +1;
		}
		i++;
	}
	printf("O maior número digitado é %d. Ele apareceu %d vezes.", maior, contador);
	return 0;
}
