#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float a, b, c;
	printf("Digite três números. \n");
	scanf("%f %f %f", &a, &b, &c);
	if(a > b && a > c){
		printf("%.2f é o maior número. \n", a);
	}else if(b > c && b > a){
		printf("%.2f é o maior número. \n", b);
	}else if(c > b && c > a){
		printf("%.2f é o maior número. \n", c);
	}else{
		printf("Os três números são iguais números iguais. \n");
	}
	return 0;
}
