#include <stdio.h>
void imprime_inteiros(int n){
	for(int i=0; i<=n; i++){
		printf("%d\n", i);
	}
}
int main(){
	imprime_inteiros(10);
	return 0;
}
