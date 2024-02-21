#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float a, b, c, delta;
	printf("Digite os coeficientes da equação quadrática. (ax^2+bx+c=0)\n a=");
	scanf("%f", &a);
	if(a == 0){
		printf("Não é equação do segundo grau. \n");
		return 0;
	}
	printf("\n b=");
	scanf("%f", &b);
	printf("\n c=");
	scanf("%f", &c);
	delta = b*b-4*a*c;
	if(delta < 0){
		printf("A equação não possui raíz real. \n");
	}else if(delta == 0){
		printf("A solução da equação é %.3f. \n", (-b)/(2*a));
	}else if(delta > 0){
		printf("As soluções da equação são: %.3f e %.3f", (-b+sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a));
	}
	return 0;
}
