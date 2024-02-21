#include <stdio.h>
#include <string.h>
float calculadora(float a, float b, char s){
	float res=0;
	if(s=='+'){
		res=a+b;
	}else if(s=='-'){
		res=a-b;
	}else if(s=='*'){
		res=a*b;
	}else if(s=='/'){
		res=a/b;
	}
	return res;
}
int main(){
	float a, b;
	char s;
	printf("Operacao: ");
	scanf("%c", &s);
	printf("Numeros: \n");
	scanf("%f %f", &a, &b);
	printf("%.3f", calculadora(a, b, s));
	return 0;
}
