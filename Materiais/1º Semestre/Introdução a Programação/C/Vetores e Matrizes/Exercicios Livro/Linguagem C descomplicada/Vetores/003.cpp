#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, a[5], soma=0;
	float media;
	for(i=0; i<5; i++){
		printf("Digite um n�mero:");
		scanf("%d", &a[i]);
		soma+=a[i];
	}
	media=soma/5.0;
	for(i=0; i<5; i++){
		printf("%d \n", a[i]);
	}
	printf("a m�dia dos n�meros � %.3f", media);
	return 0;
}
