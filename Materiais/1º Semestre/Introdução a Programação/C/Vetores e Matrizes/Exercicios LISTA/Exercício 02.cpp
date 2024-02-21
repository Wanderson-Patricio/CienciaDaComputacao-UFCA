#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int a[10], i, posicao, maior;
	for(i=0; i<10; i++){
		printf("Digite um número:");
		scanf("%d", &a[i]);
		if(i==0){
			maior=a[i];
			posicao=i+1;
		}else{
			if(a[i]>maior){
				maior=a[i];
				posicao=i+1;
			}
		}
	}
	printf("A sequência digitada foi: \n");
	for(i=0; i<10; i++){
		if(i==0){
			printf("(%d, ", a[i]);
		}else if(i==9){
			printf("%d) \n", a[i]);
		}else{
			printf("%d, ", a[i]);
		}
	}
	printf("O maior número digitado foi %d, ele foi o %dº digitado.", maior, posicao);
	return 0;
}
