#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int n, i, k;
	printf("Digite um número \n");
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		k=k*i;
	}
	printf("\n %d!=%d \n", n, k);
	return 0;
}
