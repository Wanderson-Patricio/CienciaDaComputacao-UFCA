#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int estado;
	float preco, desconto;
	printf("Qual o pre�o do seu produto? \n");
	scanf("%f", &preco);
	printf("Qual � o seu estado? \n 1 - Minas Gerais \n 2 - S�o Paulo \n 3 - Rio de Janeiro \n 4 - Mato Grosso do Sul \n");
	scanf("%d", &estado);
	switch(estado){
		case 1: desconto = 0.07*preco; break;
		case 2: desconto = 0.12*preco; break;
		case 3: desconto = 0.15*preco; break;
		case 4: desconto = 0.08*preco; break;
	}
	printf("O pre�o final do produto ser� R$%.2f \n", preco-desconto);
	return 0;
}
