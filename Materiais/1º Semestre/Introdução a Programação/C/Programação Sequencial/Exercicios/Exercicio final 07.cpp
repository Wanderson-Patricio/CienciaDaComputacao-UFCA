#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int c;
	printf("Insira a temperatura em �C. \n");
	scanf("%d", &c);
	printf("A convers�o �: \n");
	printf("%d�c � o mesmo que %.2f�F. \n", c, (float) (9.0/5)*c+32);
	return 0;
}
