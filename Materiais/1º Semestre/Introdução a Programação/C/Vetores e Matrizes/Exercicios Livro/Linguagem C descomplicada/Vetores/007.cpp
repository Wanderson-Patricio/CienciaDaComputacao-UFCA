#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, X[10], maior, menor;
	for(i=0; i<10; i++){
		printf("Digite um número:");
		scanf("%d", &X[i]);
		if(i==0){
			maior=X[i];
			menor=X[i];
		}else if(X[i]>maior){
			maior=X[i];
		}else if(X[i]<menor){
			menor=X[i];
		}
	}
	printf("maior=%d e menor=%d", maior, menor);
	return 0;
}
