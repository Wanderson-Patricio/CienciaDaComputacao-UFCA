#include <stdio.h>
#include <locale.h>
int main(){
	setlocale(LC_ALL, "portuguese");
	int n;
	printf("Quantos N�meros ser�o armazenados? \n");
	scanf("%d", &n);
	int a[n], i, j, aux;
	for(i=0; i<n; i++){
		printf("Digite o %d� n�mero:", i+1);
		scanf("%d", &a[i]);
	}
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(a[j]<a[i]){
				aux=a[i];
				a[i]=a[j];
				a[j]=aux;
			}
		}
	}
	printf("A sequ�ncia dos n�meros em ordem crescente �: \n");
	for(i=0; i<n; i++){
		if(i==0){
			printf("(%d,", a[i]);
		}else if(i==n-1){
			printf("%d)", a[i]);
		}else{
			printf("%d,", a[i]);
		}
	}
	return 0;
}
