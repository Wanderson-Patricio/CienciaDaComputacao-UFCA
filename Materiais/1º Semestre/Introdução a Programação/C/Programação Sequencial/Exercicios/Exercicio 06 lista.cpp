#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int nulos, brancos, validos, total;
	printf("Quantos dos votos foram nulos? \n");
	scanf("%d", &nulos);
	printf("Quantos dos votos foram brancos? \n");
	scanf("%d", &brancos);
	printf("Quantos dos votos foram validos? \n");
	scanf("%d", &validos);
	total = nulos + brancos + validos;
	printf("A quantidade total de votos foi: %d \n", total);
	printf("A porcentagem de votos nulos foi: %.2f %%\n", (float) (nulos)/(total)*100);
	printf("A porcentagem de votos brancos foi: %.2f %%\n", (float) (brancos)/(total)*100);
	printf("A porcentagem de votos validos foi: %.2f %%\n", (float) (validos)/(total)*100);
	return 0;
}
