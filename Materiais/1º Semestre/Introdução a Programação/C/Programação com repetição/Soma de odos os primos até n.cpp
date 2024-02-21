#include <stdio.h>
int main() {
	int p=2, j, n, divisores=0, soma=0;
	scanf("%d", &n);
	while(p<=n){
		for(j=1; j<=p; j++){
			if(p%j == 0){
				divisores++;
			}
		}
		if(divisores == 2){
			printf("%d \n", p);
			soma = soma + p;
		}
		divisores = 0;
		p++;
	}
	printf("\n %d", soma);
	return 0;
}
