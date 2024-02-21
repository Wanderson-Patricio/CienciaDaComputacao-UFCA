#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int n, i=1;
	printf("Digite um número inteiro e positivo: \n");
	scanf("%d", &n);
	while(i<=n){
		if(i*(i+1)*(i+2) == n){
			printf("%d é triangular, pois: %d = %d x %d x %d. \n", n, n, i, i+1, i+2);
			return 0;
		}
		i++;
	}
	printf("%d não é triangular. \n", n);
	return 0;
}
