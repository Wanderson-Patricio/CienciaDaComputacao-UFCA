#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int tipo;
	float kWh;
	printf("Qual o tipo de instala��o que ir� ser paga? \n");
	printf("\n 1 - Resid�ncia \n 2 - Ind�stria \n 3 - Com�ricio \n");
	scanf("%d", &tipo);
	switch(tipo){
		case 1:{
			printf("Seu tipo de instala��o � residencial.\n");
			printf("Quantos kWh foram gastos? \n");
			scanf("%f", &kWh);
			if(kWh >= 0 && kWh <= 500){
				printf("O valor a pagar ser� de R$%.2f. \n", 0.40*kWh);
			}else if(kWh > 500){
				printf("O valor a pagar ser� de R$%.2f. \n", 0.65*kWh);
			}else {
				printf("Quantidade inv�lida. \n");
			}
			break;
		}
		case 2:{
			printf("Seu tipo de instala��o � industrial.\n");
			printf("Quantos kWh foram gastos? \n");
			scanf("%f", &kWh);
			if(kWh >= 0 && kWh <= 5000){
				printf("O valor a pagar ser� de R$%.2f. \n", 0.55*kWh);
			}else if(kWh > 5000){
				printf("O valor a pagar ser� de R$%.2f. \n", 0.60*kWh);
			}else {
				printf("Quantidade inv�lida. \n");
			}
			break;
		}
		case 3:{
			printf("Seu tipo de instala��o � comercial.\n");
			printf("Quantos kWh foram gastos? \n");
			scanf("%f", &kWh);
			if(kWh >= 0 && kWh <= 1000){
				printf("O valor a pagar ser� de R$%.2f. \n", 0.55*kWh);
			}else if(kWh > 1000){
				printf("O valor a pagar ser� de R$%.2f. \n", 0.60*kWh);
			}else{
				printf("Quantidade inv�lida. \n");
			}
			break;
		}
		default: printf("tipo inv�lido. \n");
	}
	return 0;
}
