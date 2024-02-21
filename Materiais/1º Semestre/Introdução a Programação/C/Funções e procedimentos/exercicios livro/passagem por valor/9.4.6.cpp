#include<stdio.h>
float imc(float m, float h){
	float imc=m/(h*h);
	return imc;
}
int main(){
	printf("%.3f", imc(80,1.78));
	return 0;
}
