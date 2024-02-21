#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

typedef struct{
	char nome[100];
	int matricula;
	float nota1;
	float nota2;
	float nota3;
}Aluno;

float media(Aluno a){
	float soma = a.nota1 + a.nota2 + a.nota3;
	float media = soma/3.0;
	return media;
}

Aluno* maior_media(Aluno alunos[], int n){
	Aluno *maior=&alunos[0];
	for(int i=1; i<n; i++){
		if(media(alunos[i])>media(*maior)){
			maior=&alunos[i];
		}
	}
	return maior;
}

void imprime_melhor(Aluno alunos[], int n){
	Aluno *melhor=maior_media(alunos, n);
	printf("Melhor Aluno:\n");
	printf("%s\n", melhor->nome);
}

int main(){
	setlocale(LC_ALL, "portuguese");
	Aluno alunos[3]={{"Wanderson", 2022005052, 8.0, 7.0, 10},{"Raissa", 2022005050, 4, 7, 3},{"Pedro", 2022005048, 10.0, 5.0, 3.0}};
	//printf("%.2f", media(alunos[1]));
	imprime_melhor(alunos, 3);
	return 0;
}










