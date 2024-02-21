#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int x;
	printf("Digite um número \n");
	scanf("%d", &x);
	if(x%2==0){
		printf("%d é par\n", x);
	}else{
		printf("%d é ímpar\n", x);
	}
	return 0;
}
