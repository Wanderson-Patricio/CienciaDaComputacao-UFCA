#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, n, divisores=0;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		if(n%i == 0){
			divisores++;
		}
	}
	if(divisores == 2){
		printf("%d é primo", n);
	}else{
		printf("%d não é primo", n);
	}
	return 0;
}
