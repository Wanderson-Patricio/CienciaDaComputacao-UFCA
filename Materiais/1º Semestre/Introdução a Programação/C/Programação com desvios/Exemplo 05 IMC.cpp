#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float massa, altura, imc;
	printf("Qual a sua massa (em kg)? \n");
	scanf("%f", &massa);
	printf("Qual a sua altura (em m)? \n");
	scanf("%f", &altura);
	imc = (massa)/(altura*altura);
	printf("Seu imc é de %.2f. \n", imc);
	if(imc <= 20){
		printf("Abaixo de peso. \n");
	}
	if(imc > 20 && imc <= 25){
		printf("Peso normal. \n");
	}
	if(imc > 25 && imc <=30){
		printf("Acima do peso. \n");
	}
	if(imc > 30 && imc <= 40){
		printf("Obesidade. \n");
	}
	if(imc > 40){
		printf("Obesidade mórbida. \n");
	}
	return 0;
}
