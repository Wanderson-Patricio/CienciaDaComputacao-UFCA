#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float n_1, n_2, n_3, media;
	printf("Quais foram as suas notas?\n");
	printf("\n Prineira nota:");
	scanf("%f", &n_1);
	if(n_1<0 ||n_1>10){
		printf("Nota inválida");
		return 0;
	}
	printf("\n Segunda nota:");
	scanf("%f", &n_2);
	if(n_2<0 || n_2>10){
		printf("Nota inválida");
		return 0;
	}
	printf("\n Terceira nota:");
	scanf("%f", &n_3);
	if(n_3<0 || n_3>10){
		printf("Nota inválida");
		return 0;
	}
	media =(n_1+n_2+n_3)/3;
	printf("Sua media final foi: %.2f\n", media);
	if(media>=7){
		printf("Você foi aprovado :)\n");
	}else{
		printf("Você fará avaliação final :(\n");
	}
	return 0;
}
