#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int p, i=2;
	printf("Digite um número inteiro e positivo: \n");
	scanf("%d", &p);
	while(i<=p-1){
		if(p%i == 0){
			printf("%d não é primo. \n", p);
			return 0;
		}
		i++;
	}
	printf("%d é primo. \n", p);
	return 0;
}
