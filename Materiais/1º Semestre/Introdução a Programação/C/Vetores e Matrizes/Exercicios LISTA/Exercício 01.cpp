#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int n, i, a[10];
	for(i=0; i<10; i++){
		printf("Digite um número: ");
		scanf("%d", &a[i]);
	}
	printf("Escolha um número para ser subtraído dos pares:");
	scanf("%d", &n);
	for(i=0; i<10; i++){
		if(i%2==1){
			a[i]=a[i]-n;
		}
	}
	for(i=0; i<10; i++){
		printf("%d \n", a[i]);
	}
	return 0;
}
