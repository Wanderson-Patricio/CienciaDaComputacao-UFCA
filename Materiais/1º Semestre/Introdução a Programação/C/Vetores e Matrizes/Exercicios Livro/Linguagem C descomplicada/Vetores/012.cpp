#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, j, a[10], aux;
	for(i=0; i<10;i++){
		printf("Digite o %dº elemento do vetor: ", i+1);
		scanf("%d", &a[i]);
	}
	for(i=0; i<10; i++){
		for(j=i+1; j<10; j++){
			if(a[j]==a[i]){
				aux=a[i+1];
				a[i+1]=a[j];
				a[j]=aux;
			}
		}
	}
	for(i=0; i<10;i++){
		printf("%d \n", a[i]);
	}
	return 0;
}
