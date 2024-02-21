#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int idade;
	idade=32;
	printf("Roberto tem %d anos \n", idade);
	return 0;
}
