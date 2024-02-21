#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float a, b, c;
	printf("Digite três números: \n");
	scanf("%f %f %f", &a, &b, &c);
	if(a ==b && b == c){
		printf("Os três números são iguais. \n");
	}else if(a >= b && b >= c){
		printf("%.2f é o maior número e %.2f é o menor número. \n", a, c);
	}else if(a >= c && c >= b){
		printf("%.2f é o maior número e %.2f é o menor número. \n", a, b);
	}else if(b >= a && a >= c){
		printf("%.2f é o maior número e %.2f é o menor número. \n", b, c);
	}else if(b >= c && c >= a){
		printf("%.2f é o maior número e %.2f é o menor número. \n", b, a);
	}else if(c >=a && a >= b){
		printf("%.2f é o maior número e %.2f é o menor número. \n", c, b);
	}else if(c >= b && b >= a){
		printf("%.2f é o maior número e %.2f é o menor número. \n", c, a);
	}
	return 0;
}
