#include <stdio.h>
#include <locale.h>
int main(){
	setlocale(LC_ALL, "portuguese");
	int a=-1, b=1, n, i, j=1, F=0, soma=0;
	printf("Quantos n�meros ser�o somados? \n");
	scanf("%d", &n);
	while(j<=n){
		for(i=0; i<=j; i++){
			F=a+b;
			a=b;
			b=F;
		}
		soma = soma + F;
		a=-1;
		b=1;
		F=0;
		j++;
	}
	printf("A soma dos %d primeiros n�meros da sequ�ncia de Fibonacci �: %d. \n", n, soma);
	return 0;
}
