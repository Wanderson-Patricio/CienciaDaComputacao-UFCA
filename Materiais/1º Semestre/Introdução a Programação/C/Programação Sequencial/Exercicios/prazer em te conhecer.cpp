#include <stdio.h>
int main() {
	char nome[50];
	printf("Qual o seu nome? \n");
	scanf("%s", &nome);
	printf("Prazer em te conhecer %s", nome);
	return 0;
}
