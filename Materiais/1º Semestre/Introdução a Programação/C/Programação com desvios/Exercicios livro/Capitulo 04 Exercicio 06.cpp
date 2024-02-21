#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int sexo;
	float altura;
	printf("Qual é o seu sexo? \n 1 - Mulher \n 2 - Homem \n");
	scanf("%d", &sexo);
	switch(sexo){
		case 1:{
			printf("Qual a sua altura?\n");
			scanf("%f", &altura);
			printf("Seu peso ideal é: %.3f \n", 23.0*altura*altura);
			break;
		}
		case 2:{
			printf("Qual a sua altura?\n");
			scanf("%f", &altura);
			printf("Seu peso ideal é: %.3f \n", 62.1*altura-44.7);
			break;
		}
	}
	return 0;
}
