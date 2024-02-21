#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int a, b;
	printf("Digite um número. \n");
	scanf("%d", &a);
	printf("Digite outro número. \n");
	scanf("%d", &b);
	if(a%b == 0){
		printf("%d é divisível por %d.", a, b);
	}else{
		printf("%d não é divisível por %d.", a, b);
	}
	return 0;
}
