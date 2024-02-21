#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	printf("Divisão entre inteiros: %d \n", 23/10);
	printf("divisão com numerais: %.2f \n", 7.0/2);
	return 0;
}
