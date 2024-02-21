#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int c;
	printf("Insira a temperatura em ºC. \n");
	scanf("%d", &c);
	printf("A conversão é: \n");
	printf("%dºc é o mesmo que %.2fºF. \n", c, (float) (9.0/5)*c+32);
	return 0;
}
