#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int s, v;
	printf("Qual será a distância da sua viagem (em km)? \n");
	scanf("%d", &s);
	printf("Qual será a velocidade média do veículo (em km/h)? \n");
	scanf("%d", &v);
	printf("Sua viagem levará %.2f h.", (float) s/v);
	return 0;
}
