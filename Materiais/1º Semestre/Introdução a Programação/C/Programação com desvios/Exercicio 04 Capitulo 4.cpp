#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float salario, emprestimo;
	printf("Quanto � o seu sal�rio? \n R$");
	scanf("%f", &salario);
	printf("Quanto � a presta��o do empr�stimo? \n R$");
	scanf("%f", &emprestimo);
	if(emprestimo > 0.2*salario){
		printf("Empr�stimo n�o concedido. \n");
	}else{
		printf("Empr�stimo concedido. \n");
	}
	return 0;
}
