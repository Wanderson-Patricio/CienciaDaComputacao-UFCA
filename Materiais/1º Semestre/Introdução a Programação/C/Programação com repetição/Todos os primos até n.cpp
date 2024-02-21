#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int n, i, p=1, divisores=0, quantidade=0;
	scanf("%d", &n);
	printf("Os números primos entre 1 e %d (inclusive) são: \n", n);
	while(p<=n){
		for(i=1; i<=p; i++){
			if(p%i==0){
				divisores = divisores + 1;
			}
		}
		if(divisores == 2){
			printf("%d\n", p);
			quantidade++;
		}
		divisores =0;
		p++;
	}
	printf("\n Existem %d primos nesse intervalo.\n", quantidade);
	printf("A porcentagem de primos nesse intervalo é: %.2f%%", (float) (quantidade*100)/(n));
	return 0;
}
