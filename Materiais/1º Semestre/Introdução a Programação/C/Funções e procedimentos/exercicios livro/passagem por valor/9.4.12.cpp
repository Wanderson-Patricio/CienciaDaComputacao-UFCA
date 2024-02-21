#include <stdio.h>
#include <locale.h>
int primo(int n){
	int i, div=0;
	for(i=1; i<=n; i++){
		if(n%i==0){
			div++;
		}
	}
	if(div==2){
		return 1;
	}else{
		return 0;
	}
}
int maior_fator(int n){
	int maior, i;
	for(i=1; i<=n; i++){
		if(primo(i)==1){
			if(n%i==0){
				maior=i;
			}
		}
	}
	return maior;
}
int main(){
	setlocale(LC_ALL, "portuguese");
	int n;
	scanf("%d",&n);
	printf("O maior fator primo de %d é %d.", n, maior_fator(n));
	return 0;
}
