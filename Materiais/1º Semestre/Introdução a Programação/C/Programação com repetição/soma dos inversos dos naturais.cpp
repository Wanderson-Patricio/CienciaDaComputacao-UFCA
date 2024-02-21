#include <stdio.h>
int main() {
	int n, i = 1;
	float soma = 0;
	scanf("%d", &n);
	while(i<=n){
		soma = soma + (float) 1/i;
		i++;
	}
	printf("\n %f", soma);
	return 0;
}
