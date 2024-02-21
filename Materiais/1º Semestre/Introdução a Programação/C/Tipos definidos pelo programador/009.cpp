#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

typedef struct{
	char nome[100];
	char esporte[50];
	int idade;
	float altura;
}Atleta;

void ordena_idade(Atleta atlet[], int n){
	Atleta Aux;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(atlet[j].idade>atlet[i].idade){
				Aux = atlet[i];
				atlet[i] = atlet[j];
				atlet[j] = Aux;
			}
		}
	}
	printf("A ordenação dos atletas em ordem de idade é:\n");
	for(int i=0; i<n; i++){
		printf("%s, %d anos (%s).\n", atlet[i].nome, atlet[i].idade, atlet[i].esporte);
	}
}

void ordena_altura(Atleta atlet[], int n){
	Atleta Aux;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(atlet[j].altura>atlet[i].altura){
				Aux = atlet[i];
				atlet[i] = atlet[j];
				atlet[j] = Aux;
			}
		}
	}
	printf("A ordenação dos atletas em ordem de altura é:\n");
	for(int i=0; i<n; i++){
		printf("%s, %.2f metros (%s).\n", atlet[i].nome, atlet[i].altura, atlet[i].esporte);
	}
}

int main(){
	setlocale(LC_ALL, "portuguese");
	Atleta atletas[3] = {{"Wanderson", "Futebol", 20, 1.80}, {"Thayná", "Vôlei", 20, 1.64}, {"Eduardo", "Basquete", 22, 1.75}};
	ordena_idade(atletas, 3);
	ordena_altura(atletas, 3);
	return 0;
}
