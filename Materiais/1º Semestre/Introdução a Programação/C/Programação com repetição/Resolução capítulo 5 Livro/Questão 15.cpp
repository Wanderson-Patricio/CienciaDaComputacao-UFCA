#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int numero=0, maior, menor;
	printf("Digite um n�mero: \n");
	scanf("%d", &numero);
	maior = numero;
	menor = numero;
	while(numero>=0){
		printf("Digite um n�mero: \n");
		scanf("%d", &numero);
		if(numero>maior){
			maior = numero;
		}else if((numero<menor) && (numero>=0)){
			menor = numero;
		}
	}
	printf("O maior n�mero digitado foi %d e o menor n�mero digitado foi %d.", maior, menor);
	return 0;
}
