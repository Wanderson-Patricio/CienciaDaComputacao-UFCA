#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int a;
	printf("Digite um n�mero: \n");
	scanf("%d", &a);
	switch(a){
		case 1: printf("Lave as m�os. \n"); break;
		case 2: printf("Passe �lccol em gel. \n"); break;
		case 3: printf("Use m�scara. \n"); break;
		case 4: printf("Cuide dos idosos. \n"); break;
		case 5: printf("Cultive paci�ncia. \n"); break;
		case 6: printf("Cultive sabedoria. \n"); break;
		case 7: printf("Ame o pr�ximo. \n"); break;
		case 8: printf("Exercite a disciplina. \n"); break;
		case 9: printf("Acalme a mente. \n"); break;
		default: printf("C�digo inv�lido. \n"); break;
	}
	return 0;
}
