#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int n;
	printf("Quantos elementos ter� o vetor? \n");
	scanf("%d", &n);
	int a[n], i;
	float m, soma=0, desvio;
	for(i=0; i<n; i++){
		printf("Digite o %d� elemento: ", i+1);
		scanf("%d", &a[i]);
		soma+=a[i];
	}
	m= (float) soma/n;
	soma=(float) soma/(n-1);
	desvio=sqrt(soma-m);
	if(soma-m<=0){
		printf("O desvio padr�o n�o est� definido nos reais.");
	}else{
		printf("O desvio padr�o dese vetor �: %.4f.", desvio);
	}
	return 0;
}
