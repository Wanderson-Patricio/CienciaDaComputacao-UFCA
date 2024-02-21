#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(){
	setlocale(LC_ALL, "portuguese");
	FILE *arq;
	char string[1000];
	char *aux;
	arq = fopen("profissoes.txt", "r");
	if(arq == NULL){
		printf("Erro na leitura do arquivo.\n");
		system("pause");
		exit(1);
	}
	
	aux = fgets(string,1000,arq);
	printf("%s", string);
	
	fclose(arq);
	return 0;
}
