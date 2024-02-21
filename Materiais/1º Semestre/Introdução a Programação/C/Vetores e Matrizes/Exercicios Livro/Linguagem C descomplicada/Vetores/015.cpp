#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int a[10], i, j, aux;
	for(i=0; i<10; i++){
		printf("Digite o %dº elemento: ", i+1);
		scanf("%d", &a[i]);
	}
	for(i=0; i<10; i++){
		for(j=i; j<10; j++){
			if(a[j]<a[i]){
				aux=a[i];
				a[i]=a[j];
				a[j]=aux;
			}
		}
	}
	for(i=-1; i<10; i++){
		if(i==-1){
			printf("\n V=");
		}else if(i==0){
			printf("(%d,", a[i]);
		}else if(i==9){
			printf("%d) \n", a[i]);
		}else{
			printf("%d,", a[i]);
		}
	}
	return 0;
}
