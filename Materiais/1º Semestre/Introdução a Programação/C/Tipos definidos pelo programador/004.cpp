#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

typedef struct{
	float x;
	float y;
}Ponto;

typedef struct{
	Ponto superior;
	Ponto inferior;
}Retangulo;

float diag(Retangulo r){
	float diag=sqrt(pow(r.superior.x-r.inferior.x,2)+pow(r.superior.y-r.inferior.y,2));
	return diag;
}

float area(Retangulo r){
	return abs(r.superior.x-r.inferior.x)*abs(r.superior.y-r.inferior.y);
}

float perimetro(Retangulo r){
	return 2*(abs(r.superior.x-r.inferior.x)+abs(r.superior.y-r.inferior.y));
}

int main(){
	setlocale(LC_ALL, "portuguese");
	Retangulo ret={{1.0,2.0},{5.0,5.0}};
	printf("%.3f,  %.3f  %.3f", diag(ret), area(ret), perimetro(ret));
	return 0;
}
