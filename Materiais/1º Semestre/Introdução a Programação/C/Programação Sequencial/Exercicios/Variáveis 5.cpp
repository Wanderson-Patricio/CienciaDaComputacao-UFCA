#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int a, b;
	a=45;
	b=34;
	printf("soma: %d \n", a+b);
	printf("subtra��o: %d \n", a-b);
	printf("Multiplica��o: %d \n", a*b);
	printf("Divis�o: %.2f \n", (float) a/b);
	return 0;
}
