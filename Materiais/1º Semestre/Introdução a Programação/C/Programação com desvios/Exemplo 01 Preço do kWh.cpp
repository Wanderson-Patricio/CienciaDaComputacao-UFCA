#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int tipo;
	float kWh;
	printf("Qual o tipo de instalação que irá ser paga? \n");
	printf("\n 1 - Residência \n 2 - Indústria \n 3 - Coméricio \n");
	scanf("%d", &tipo);
	switch(tipo){
		case 1:{
			printf("Seu tipo de instalação é residencial.\n");
			printf("Quantos kWh foram gastos? \n");
			scanf("%f", &kWh);
			if(kWh >= 0 && kWh <= 500){
				printf("O valor a pagar será de R$%.2f. \n", 0.40*kWh);
			}else if(kWh > 500){
				printf("O valor a pagar será de R$%.2f. \n", 0.65*kWh);
			}else {
				printf("Quantidade inválida. \n");
			}
			break;
		}
		case 2:{
			printf("Seu tipo de instalação é industrial.\n");
			printf("Quantos kWh foram gastos? \n");
			scanf("%f", &kWh);
			if(kWh >= 0 && kWh <= 5000){
				printf("O valor a pagar será de R$%.2f. \n", 0.55*kWh);
			}else if(kWh > 5000){
				printf("O valor a pagar será de R$%.2f. \n", 0.60*kWh);
			}else {
				printf("Quantidade inválida. \n");
			}
			break;
		}
		case 3:{
			printf("Seu tipo de instalação é comercial.\n");
			printf("Quantos kWh foram gastos? \n");
			scanf("%f", &kWh);
			if(kWh >= 0 && kWh <= 1000){
				printf("O valor a pagar será de R$%.2f. \n", 0.55*kWh);
			}else if(kWh > 1000){
				printf("O valor a pagar será de R$%.2f. \n", 0.60*kWh);
			}else{
				printf("Quantidade inválida. \n");
			}
			break;
		}
		default: printf("tipo inválido. \n");
	}
	return 0;
}
