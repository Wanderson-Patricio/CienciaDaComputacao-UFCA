#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i;
	float nota, soma=0, media;
	for(i=1; i<=3; i++){
		printf("Digite sua nota na avalia��o %d: \n", i);
		scanf("%f", &nota);
		while((nota<0) || (nota>10)){
			printf("Essa n�o � v�lida. \n Digite novamente:\n");
			scanf("%f", &nota);
		}
		soma = soma + nota;
	}
	media =soma/3;
	printf("Sua m�dia foi: %.2f. \n", media);
	if(media>=7){
		printf("Parab�ns, voc� foi aprovado!! \n");
	}else{
		printf("Voc� far� Avalia��o Final. \n");
	}
	return 0;
}
