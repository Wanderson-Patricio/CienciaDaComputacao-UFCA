#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int x, y, i = 1, soma = 0;
	printf("Digite dois números inteiros e positivos: \n");
	scanf("%d %d", &x, &y);
	while(i <= y){
		soma = soma +x;
		i++;
	}
	printf("%d x %d = %d \n", x, y, soma);
	return 0;
}
