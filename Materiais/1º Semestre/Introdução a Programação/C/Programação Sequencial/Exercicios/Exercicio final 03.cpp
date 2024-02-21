#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	int D, H, M, S, soma;
	printf("Há quanto tempo você está usando este aplicativo? \n");
	printf("Dias:");
	scanf("%d", &D);
	printf("Horas:");
	scanf("%d", &H);
	printf("Minutos:");
	scanf("%d", &M);
	printf("Segundos:");
	scanf("%d", &S);
	soma = 86400*D+3600*H+60*M+S;
	printf("Você está usando este aplicativo a %d segundos. \n", soma);
	return 0;
}
