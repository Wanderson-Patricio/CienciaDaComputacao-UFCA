#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int s, v;
	printf("Qual ser� a dist�ncia da sua viagem (em km)? \n");
	scanf("%d", &s);
	printf("Qual ser� a velocidade m�dia do ve�culo (em km/h)? \n");
	scanf("%d", &v);
	printf("Sua viagem levar� %.2f h.", (float) s/v);
	return 0;
}
