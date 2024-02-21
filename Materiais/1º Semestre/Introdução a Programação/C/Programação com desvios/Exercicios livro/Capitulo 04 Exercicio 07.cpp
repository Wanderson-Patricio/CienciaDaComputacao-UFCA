#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int estado;
	float preco, desconto;
	printf("Qual o preço do seu produto? \n");
	scanf("%f", &preco);
	printf("Qual é o seu estado? \n 1 - Minas Gerais \n 2 - São Paulo \n 3 - Rio de Janeiro \n 4 - Mato Grosso do Sul \n");
	scanf("%d", &estado);
	switch(estado){
		case 1: desconto = 0.07*preco; break;
		case 2: desconto = 0.12*preco; break;
		case 3: desconto = 0.15*preco; break;
		case 4: desconto = 0.08*preco; break;
	}
	printf("O preço final do produto será R$%.2f \n", preco-desconto);
	return 0;
}
