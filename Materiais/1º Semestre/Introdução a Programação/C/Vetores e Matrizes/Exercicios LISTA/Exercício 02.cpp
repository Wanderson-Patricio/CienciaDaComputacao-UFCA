#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int a[10], i, posicao, maior;
	for(i=0; i<10; i++){
		printf("Digite um n�mero:");
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
	printf("A sequ�ncia digitada foi: \n");
	for(i=0; i<10; i++){
		if(i==0){
			printf("(%d, ", a[i]);
		}else if(i==9){
			printf("%d) \n", a[i]);
		}else{
			printf("%d, ", a[i]);
		}
	}
	printf("O maior n�mero digitado foi %d, ele foi o %d� digitado.", maior, posicao);
	return 0;
}
