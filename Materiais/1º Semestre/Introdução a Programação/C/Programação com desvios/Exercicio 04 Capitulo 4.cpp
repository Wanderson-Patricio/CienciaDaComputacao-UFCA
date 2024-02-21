#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float salario, emprestimo;
	printf("Quanto é o seu salário? \n R$");
	scanf("%f", &salario);
	printf("Quanto é a prestação do empréstimo? \n R$");
	scanf("%f", &emprestimo);
	if(emprestimo > 0.2*salario){
		printf("Empréstimo não concedido. \n");
	}else{
		printf("Empréstimo concedido. \n");
	}
	return 0;
}
