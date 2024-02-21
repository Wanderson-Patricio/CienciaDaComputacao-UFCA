#include <stdio.h>
#include <math.h>
int fat(int n){
	int res=1;
	for(int i=1; i<=n; i++){
		res*=i;
	}
	return res;
}
float e(int n){
	float soma=0;
	for(int i=0; i<=n; i++){
		soma+=(float) 1/fat(i);
	}
	return soma;
}
int main(){
	int x;
	scanf("%d", &x);
	printf("%.8f", e(x));
	return 0;
}
