#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int n=0;
	while((n<=0)||(n>20)){
		printf("Quantos números serão armazenados? \n");
		scanf("%d", &n);
	}
	int i, a[n], c[n];
	for(i=0; i<n; i++){
		printf("Digite o %dº elemento do vetor: ", i+1);
		scanf("%d", &a[i]);
		c[i]=pow(a[i],2);
	}
	for(i=-1; i<n; i++){
		if(i==-1){
			printf("A=");
		}else if(i==0){
			printf("(%d,", a[i]);
		}else if(i==n-1){
			printf("%d) \n", a[i]);
		}else{
			printf("%d,", a[i]);
		}
	}
	for(i=-1; i<n; i++){
		if(i==-1){
			printf("C=");
		}else if(i==0){
			printf("(%d,", c[i]);
		}else if(i==n-1){
			printf("%d)", c[i]);
		}else{
			printf("%d,", c[i]);
		}
	}
	return 0;
}
