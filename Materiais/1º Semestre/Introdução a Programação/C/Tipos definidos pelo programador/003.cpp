#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

typedef struct{
	float x;
	float y;
}Ponto;

float dist(Ponto a, Ponto b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

int main(){
	setlocale(LC_ALL, "portuguese");
	Ponto p1={1.0,2.0}, p2={5.0,5.0};
	printf("%.3f", dist(p1,p2));
	return 0;
}
