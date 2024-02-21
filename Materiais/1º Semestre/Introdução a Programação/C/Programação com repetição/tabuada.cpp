#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int x, i;
	printf("Digite um número: \n")/
	scanf("%d", &x);
	for(i=1; i<=9; i++){
		printf("%dx%d=%d \n", i, x, x*i);
	}
	return 0;
}
