#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float a, b, c, delta;
	printf("Digite os coeficientes da equa��o quadr�tica. (ax^2+bx+c=0)\n a=");
	scanf("%f", &a);
	if(a == 0){
		printf("N�o � equa��o do segundo grau. \n");
		return 0;
	}
	printf("\n b=");
	scanf("%f", &b);
	printf("\n c=");
	scanf("%f", &c);
	delta = b*b-4*a*c;
	if(delta < 0){
		printf("A equa��o n�o possui ra�z real. \n");
	}else if(delta == 0){
		printf("A solu��o da equa��o � %.3f. \n", (-b)/(2*a));
	}else if(delta > 0){
		printf("As solu��es da equa��o s�o: %.3f e %.3f", (-b+sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a));
	}
	return 0;
}
