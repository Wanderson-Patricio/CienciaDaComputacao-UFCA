#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int a=-1, b=1, F=0, n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		F=a+b;
		a=b;
		b=F;
	}
	printf("O termo %d da sequência de Fibonacci é %d.", n, F);
	return 0;
}
