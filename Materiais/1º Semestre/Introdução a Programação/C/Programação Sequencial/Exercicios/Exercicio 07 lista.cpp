#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int dias, quilometros;
	float preco;
	printf("Durante quantos dias voc� alugou o carro? \n");
	scanf("%d", &dias);
	printf("Quantos quilometros voc� rodou com o carro? \n");
	scanf("%d", &quilometros);
	preco = 60.00*dias + 0.15*quilometros;
	printf("O pre�o total a pagar ser�: R$%.2f \n", preco);
	return 0;
}
