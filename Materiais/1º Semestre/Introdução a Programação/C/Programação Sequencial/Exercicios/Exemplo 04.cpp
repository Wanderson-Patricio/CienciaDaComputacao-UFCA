#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int numero;
	char letra;
	printf("Digite um n�mero inteiro e uma letra. \n");
	scanf("%d %c", &numero, &letra);
	printf("Valores digitados: %d , %c", numero, letra);
	return 0;
}
