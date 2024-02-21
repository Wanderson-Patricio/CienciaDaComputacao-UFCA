#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int n, i;
	scanf("%d", &n);
	printf("Os divisores de %d são: \n", n);
	for(i=1; i<=n; i++){
		if(n%i == 0){
			printf("%d \n", i);
		}
	}
	return 0;
}
