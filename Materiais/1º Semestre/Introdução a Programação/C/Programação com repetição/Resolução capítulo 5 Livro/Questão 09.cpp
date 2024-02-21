#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i=1, numero, maior, menor;
	printf("Digite um número:\n");
	scanf("%d", &numero);
	maior = numero;
	menor = numero;
	while(i<=9){
		printf("Digite um número:\n");
		scanf("%d", &numero);
		if(numero>maior){
			maior = numero;
		}else if(numero<menor){
			menor = numero;
		}
		i++;
	}
	printf("O maior número é %d e o menor número é %d.", maior, menor);
	return 0;
}
