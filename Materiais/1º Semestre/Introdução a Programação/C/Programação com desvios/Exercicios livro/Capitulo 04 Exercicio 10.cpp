#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float x, y, z, media;
	int tipo;
	printf("Digite três números. \n");
	scanf("%f %f %f", &x, &y, &z);
	printf("Escolha a média a ser feita? \n 1 - Geométrica \n 2 - Ponderada \n 3 - Harmônica \n 4 - Aritmética \n");
	scanf("%d", &tipo);
	switch(tipo){
		case 1: media = cbrt(x*y*z); break;
		case 2: media = (x+2*y+3*z)/6; break;
		case 3: media = 1/((1/x)+(1/y)+(1/z)); break;
		case 4: media = (x+y+z)/3; break;
		default: {
			printf("Operação inválida \n");
			return 0;
			break;
		}
	}
	printf("A média é: %.3f", media);
	return 0;
}
