#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

typedef struct{
	int h;
	int min;
	int s;
}Horario;

int conv_horario(Horario hora){
	int z = hora.h*3600 + hora.min*60 + hora.s;
	return z;
}

void maior_horario(Horario hora[], int n){
	int maior = conv_horario(hora[0]);
	Horario *maior_hora;
	maior_hora = &hora[0];
	for(int i=0; i<n; i++){
		if(conv_horario(hora[i])>maior){
			maior = conv_horario(hora[i]);
			maior_hora = &hora[i];
		}
	}
	printf("%dh %dmin %ds \n", maior_hora->h, maior_hora->min, maior_hora->s);
}

int main(){
	setlocale(LC_ALL, "portuguese");
	Horario hora[4] = {{1,10,50},{1,12,50},{2, 5, 10},{3,0,0}};
	maior_horario(hora, 4);
	return 0;
}










