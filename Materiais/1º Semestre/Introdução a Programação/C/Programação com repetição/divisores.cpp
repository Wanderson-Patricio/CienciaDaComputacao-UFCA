#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int n, i, divisores = 0;
	printf("Digite um n�mero: \n");
	scanf("%d", &n);
	printf("Os divisores de %d s�o: \n", n);
	for(i=1; i<=n; i++){
		if(n%i == 0){
			printf("%d \n", i);
			divisores++;
		}
	}
	printf("\n %d tem %d divisores.", n, divisores);
	return 0;
}
