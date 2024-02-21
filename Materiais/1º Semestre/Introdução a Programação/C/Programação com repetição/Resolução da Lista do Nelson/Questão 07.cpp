#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i;
	float numero, maior;
	printf("Digite um número: \n");
	scanf("%f", &numero);
	maior = numero;
	for(i=1; i<=9; i++){
		printf("Digite um número: \n");
		scanf("%f", &numero);
		if(numero>maior){
			maior = numero;
		}
	}
	printf("Dentre os números digitados, o maior foi %.2f. \n", maior);
	return 0;
}
