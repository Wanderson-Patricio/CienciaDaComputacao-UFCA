#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, n;
	float soma = 0;
	printf("Digite um número: \n");
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		soma = soma + (pow(-1,i+1))/i;
	}
	printf("%.5f \n", soma);
	return 0;
}
