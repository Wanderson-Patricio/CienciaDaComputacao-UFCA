#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int a, b;
	printf("Digite um n�mero. \n");
	scanf("%d", &a);
	printf("Digite outro n�mero. \n");
	scanf("%d", &b);
	if(a%b == 0){
		printf("%d � divis�vel por %d.", a, b);
	}else{
		printf("%d n�o � divis�vel por %d.", a, b);
	}
	return 0;
}
