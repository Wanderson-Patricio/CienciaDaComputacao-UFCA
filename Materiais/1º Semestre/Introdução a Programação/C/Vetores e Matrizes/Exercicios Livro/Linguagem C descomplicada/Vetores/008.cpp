#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, v[10], neg=0, soma=0;
	for(i=0; i<10; i++){
		printf("Digite um n�mero: ");
		scanf("%d", &v[i]);
		if(v[i]<0){
			neg++;
		}else{
			soma+=v[i];
		}
	}
	printf("Foram digitados %d n�meros negativos. \n", neg);
	printf("A soma dos positivos � %d.", soma);
	return 0;
}
