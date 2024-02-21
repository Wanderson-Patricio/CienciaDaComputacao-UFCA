#include <stdio.h>
#include <math.h>
int main() {
	int n, i = 1;
	float soma = 0;
	scanf("%d", &n);
	while(i<=n){
		soma = soma + (float) 1/(i*i);
		i++;
	}
	printf("\n %f \n", soma);
	return 0;
}
