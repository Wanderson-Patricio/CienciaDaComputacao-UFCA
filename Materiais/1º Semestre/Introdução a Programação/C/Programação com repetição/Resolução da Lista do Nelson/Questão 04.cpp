#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int n, i=1;
	printf("Digite um n�mero inteiro e positivo: \n");
	scanf("%d", &n);
	while(i<=n){
		if(i*(i+1)*(i+2) == n){
			printf("%d � triangular, pois: %d = %d x %d x %d. \n", n, n, i, i+1, i+2);
			return 0;
		}
		i++;
	}
	printf("%d n�o � triangular. \n", n);
	return 0;
}
