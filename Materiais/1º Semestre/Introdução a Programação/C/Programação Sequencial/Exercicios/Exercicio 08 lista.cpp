#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float salario, imposto, sindicato, salario_liquido;
	printf("Qual � o seu sal�rio:\n R$");
	scanf("%f", &salario);
	imposto = 0.08*salario;
	sindicato = 0.05*salario;
	salario_liquido = salario-imposto-sindicato;
	printf("Sal�rio bruto: R$%.2f\n", salario);
	printf("Imposto pago: R$%.2f\n", imposto);
	printf("Sindicato pago: R$%.2f\n", sindicato);
	printf("Sal�rio l�quido: R$%.2f\n", salario_liquido);
	return 0; 
}
