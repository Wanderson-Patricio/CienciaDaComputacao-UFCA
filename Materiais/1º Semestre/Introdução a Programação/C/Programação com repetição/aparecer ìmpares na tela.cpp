#include <locale.h>
#include <stdio.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int n, i;
	printf("Digite um número \n");
	scanf("%d", &n);
	printf("\n");
	for(i=1; i<=n; i++){
		if(i%2 == 1){
			printf("%d \n", i);
		}
	}
	return 0;
}
