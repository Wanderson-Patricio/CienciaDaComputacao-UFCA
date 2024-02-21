#include <stdio.h>
float soma(int n){
	float soma=0;
	for(int i=1; i<=n; i++){
		soma+=(float) (i*i+1)/(i+3);
	}
	return soma;
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%.5f", soma(n));
	return 0;
}
