#include <stdio.h>
int primo(int n){
	int i, divisores=0;
	for(i=1; i<=n; i++){
		if(n%i==0){
			divisores++;
		}
	}
	if(divisores==2){
		return 1;
	}else{
		return 0;
	}
}
int fibonacci(int n){
	if((n==1)||(n==2)){
		return 1;
	}else{
		return fibonacci(n-1)+fibonacci(n-2);
	}
}
int main() {
	int i, cont=0, n;
	printf("Até qual número será contado? \n");
	scanf("%d", &n);
	for(i=1; i<n; i++){
		if(primo(fibonacci(i)==1)){
			printf("%d \n", fibonacci(i));
			cont++;
		}
	}
	printf("Existem %d primos.", cont);
	return 0;
}
