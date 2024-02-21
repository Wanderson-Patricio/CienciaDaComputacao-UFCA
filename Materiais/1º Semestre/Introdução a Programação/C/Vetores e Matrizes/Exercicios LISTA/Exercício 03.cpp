#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int a[10], i, x, contador=0, b[10];
	printf("Digite um número a ser considerado para a multiplicidade: ");
	scanf("%d", &x);
	while((x==1)||(x==0)){
		if(x==1){
			printf("Todos os números são múltiplos de 1. \n Digite outro número:");
			scanf("%d", &x);
		}
		if(x==0){
			printf("Não existe divisão por 0. \n Digite outro número:");
			scanf("%d", &x);
		}
	}
	for(i=0; i<10; i++){
		printf("Digite um número:");
		scanf("%d", &a[i]);
		if(a[i]%x==0){
			b[i]=a[i];
			contador++;
		}else{
			b[i]=1;
		}
	}
	printf("existem %d divisores de %d no conjunto dos números digitados. Estes são: \n", contador, x);
	for(i=0; i<10;i++){
		if(b[i]==1){
			continue;
		}
		printf("%d, ", b[i]);
	}
	return 0;
}
