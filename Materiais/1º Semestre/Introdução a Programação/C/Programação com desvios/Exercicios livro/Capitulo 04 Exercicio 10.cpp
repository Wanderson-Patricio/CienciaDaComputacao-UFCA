#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float x, y, z, media;
	int tipo;
	printf("Digite tr�s n�meros. \n");
	scanf("%f %f %f", &x, &y, &z);
	printf("Escolha a m�dia a ser feita? \n 1 - Geom�trica \n 2 - Ponderada \n 3 - Harm�nica \n 4 - Aritm�tica \n");
	scanf("%d", &tipo);
	switch(tipo){
		case 1: media = cbrt(x*y*z); break;
		case 2: media = (x+2*y+3*z)/6; break;
		case 3: media = 1/((1/x)+(1/y)+(1/z)); break;
		case 4: media = (x+y+z)/3; break;
		default: {
			printf("Opera��o inv�lida \n");
			return 0;
			break;
		}
	}
	printf("A m�dia �: %.3f", media);
	return 0;
}
