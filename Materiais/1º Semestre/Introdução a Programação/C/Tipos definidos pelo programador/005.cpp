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

int esta(Retangulo r, Ponto p){
	int result = 1;
	if((p.x<r.superior.x)||(p.x>r.inferior.x)||(p.y<r.inferior.y)||(p.y>r.superior.y)){
		result = 0;
	}
	return result;
}

int main(){
	setlocale(LC_ALL, "portuguese");
	Retangulo ret={{5.0,5.0},{1.0,2.0}};
	Ponto p={1.0,9.0};
	switch(esta(ret, p)){
		case 1: printf("O ponto está no retângulo"); break;
		case 0: printf("O ponto não está no retângulo"); break;
	}
	return 0;
}
