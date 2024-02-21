#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int divida, compra;
	divida = 0;
	compra = 100;
	divida = divida + compra;
	compra = 200;
	divida = divida + compra;
	compra = 300;
	divida = divida + compra;
	printf("Dívida = R$%.2f \n", (float) divida);
	return 0;
}
