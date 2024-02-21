#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(){
	setlocale(LC_ALL, "portuguese");
	FILE *arq;
	arq = fopen("profissoes.txt", "a+");
	if(arq == NULL){
		printf("Erro na leitura do arquivo.\n");
		system("pause");
		exit(1);
	}
	
	char c;
	//char string[100];
	//gets(string);
	
	//fputc('\n', arq);
	while((c = fgetc(arq)) != EOF){
		printf("%c", c);
	}
	
	fclose(arq);
	return 0;
}
