#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, n, soma=0;
	scanf("%d", &n);
	for(i=1; i<=n-1; i++){
		if(n%i==0){
			soma = soma +i;
		}
	}
	printf("%d", soma);
	return 0;
}
