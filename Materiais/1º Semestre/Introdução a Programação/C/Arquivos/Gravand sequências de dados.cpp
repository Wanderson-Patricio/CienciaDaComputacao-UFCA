#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{
	char nome[100];
	float notas[3];
	int matricula;
}Aluno;

int main(){
	FILE *arq;
	arq = fopen("ArqGrav.txt","wb");
	if(arq == NULL){
		printf("Problemas na CRIACAO do arquivo\n");
		system("pause");
		exit(1);
	}
	int v[5] = {1,2,3,4,5};
	
	//grava todo o array no arquivo (5 posições)
	fwrite(v,sizeof(int),5,arq);
	
	fclose(arq);
	system("pause");
	return 0;
}
