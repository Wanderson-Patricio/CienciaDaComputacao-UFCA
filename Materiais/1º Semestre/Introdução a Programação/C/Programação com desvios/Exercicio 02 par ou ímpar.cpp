#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int x;
	printf("Digite um n�mero \n");
	scanf("%d", &x);
	if(x%2==0){
		printf("%d � par\n", x);
	}else{
		printf("%d � �mpar\n", x);
	}
	return 0;
}
