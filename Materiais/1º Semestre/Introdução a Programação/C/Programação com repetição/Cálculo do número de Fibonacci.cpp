#include <stdio.h>
#include <locale.h>
#include <math.h>
/*
A sequência de Fibonacci é: 0,1,1,2,3,5,8,13,21,34,54,...
*/
int main() {
	setlocale(LC_ALL, "portuguese");
	int a, b, F, i, n;
	a=-1;
	b=1;
	printf("Qual o número que você quer ver? \n");
	scanf("%d", &n);
	printf("\n");
	for(i=0; i<=n; i++){
		F=a+b;
		a=b;
		b=F;
		if(F==0){
			continue;
		}
		printf("%d \n", F);
	}
	return 0;
}
