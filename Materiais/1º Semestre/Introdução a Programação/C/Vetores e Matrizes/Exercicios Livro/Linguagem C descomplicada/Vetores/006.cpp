#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, a[10], pares=0;
	for(i=0; i<10; i++){
		printf("Digite um n�mero:");
		scanf("%d", &a[i]);
		if(a[i]%2==0){
			pares++;
		}
	}
	printf("Foram digitados %d n�meros pares.", pares);
	return 0;
}
