#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float a, b, c;
	printf("Digite tr�s n�meros: \n");
	scanf("%f %f %f", &a, &b, &c);
	if(a ==b && b == c){
		printf("Os tr�s n�meros s�o iguais. \n");
	}else if(a >= b && b >= c){
		printf("%.2f � o maior n�mero e %.2f � o menor n�mero. \n", a, c);
	}else if(a >= c && c >= b){
		printf("%.2f � o maior n�mero e %.2f � o menor n�mero. \n", a, b);
	}else if(b >= a && a >= c){
		printf("%.2f � o maior n�mero e %.2f � o menor n�mero. \n", b, c);
	}else if(b >= c && c >= a){
		printf("%.2f � o maior n�mero e %.2f � o menor n�mero. \n", b, a);
	}else if(c >=a && a >= b){
		printf("%.2f � o maior n�mero e %.2f � o menor n�mero. \n", c, b);
	}else if(c >= b && b >= a){
		printf("%.2f � o maior n�mero e %.2f � o menor n�mero. \n", c, a);
	}
	return 0;
}
