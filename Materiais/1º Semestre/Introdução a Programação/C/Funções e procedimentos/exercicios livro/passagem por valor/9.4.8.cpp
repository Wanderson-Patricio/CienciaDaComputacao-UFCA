#include <stdio.h>
#include <locale.h>
int verifica_quadrado(int n){
	int verificador=0;
	for(int i=0; i<=n; i++){
		if(n==i*i){
			verificador=1;
			break;
		}
	}
	return verificador;
}
void quadrado(int n){
	if(verifica_quadrado(n)==1){
		printf("%d é quadrado perfeito.\n", n);
	}else{
		printf("%d não é quadrado perfeito.\n", n);
	}
}
int main(){
	setlocale(LC_ALL, "portuguese");
	quadrado(3);
	return 0;
}
