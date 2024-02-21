//Lendo um arquivo gravado
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(){
	setlocale(LC_ALL, "portuguese");
	FILE *arq;
	arq = fopen("ArqGrav.txt", "rb");
	if(arq == NULL){
		printf("Erro na leitura do arquivo.\n");
		system("pause");
		exit(1);
	}
	
	int i,total_lido, v[5];
	//lê 5 posições inteiras do arquivos
	total_lido = fread(v,sizeof(int),5,arq);
	if(total_lido != 5){
		printf("Erro na leitura do arquivo!");
		system("pause");
		exit(1);
	}else{
		for(i = 0; i < 5; i++){
			printf("v[%d] = %d\n",i,v[i]);
		}
	}
	
	fclose(arq);
	return 0;
}
