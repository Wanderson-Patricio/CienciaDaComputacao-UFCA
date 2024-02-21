#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

typedef struct{
	char nome[100];
	int matricula;
	float notas[3];
}Aluno;

int main(){
	setlocale(LC_ALL, "portuguese");
	printf("%d", sizeof(Aluno));
	return 0;
}
