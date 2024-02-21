#include <stdio.h>
#include <math.h>
int fat(int n){
	int res=1;
	for(int i=1; i<=n; i++){
		res*=i;
	}
	return res;
}
float sine(float x){
	x=x*(3.141592/180);
	float soma=0, mult;
	for(int i=0; i<=5; i++){
		mult=(float) pow(-1, i)/(fat(2*i+1));
		soma+=mult*pow(x, 2*i+1);
	}
	return soma;
}
int main(){
	float x;
	scanf("%f", &x);
	printf("%.5f", sine(x));
	return 0;
}
