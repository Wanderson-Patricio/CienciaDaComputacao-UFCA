#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float a, b, c;
	printf("Digite tr�s n�meros. \n");
	scanf("%f %f %f", &a, &b, &c);
	if(a > b && a > c){
		printf("%.2f � o maior n�mero. \n", a);
	}else if(b > c && b > a){
		printf("%.2f � o maior n�mero. \n", b);
	}else if(c > b && c > a){
		printf("%.2f � o maior n�mero. \n", c);
	}else{
		printf("Os tr�s n�meros s�o iguais n�meros iguais. \n");
	}
	return 0;
}
