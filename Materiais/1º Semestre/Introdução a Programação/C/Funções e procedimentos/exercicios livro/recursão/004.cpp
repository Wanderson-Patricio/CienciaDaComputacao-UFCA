#include <stdio.h>
void imprime_inteiros(int n){
	if(n==0){
		printf("0");
	}else{
		printf("%d\n", n);
		imprime_inteiros(n-1);
	}
}
int main(){
	imprime_inteiros(60);
	return 0;
}
