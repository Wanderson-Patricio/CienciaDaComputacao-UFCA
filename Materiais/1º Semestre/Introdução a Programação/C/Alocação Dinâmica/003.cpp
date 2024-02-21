#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

typedef struct{
	char rua[50];
	int numero;
}Endereco;

typedef struct{
	char nome[100];
	int idade;
	Endereco endereco;
}Cadastro;

Cadastro* guarda_cad(int n){
	Cadastro* cad = (Cadastro*)malloc(n*sizeof(Cadastro));
	return cad;
}

int main(){
	setlocale(LC_ALL, "portuguese");
	int n, i;
	char name[100];
	printf("Quantos cadastros ser�o guardados?\n");
	scanf("%d", &n);
	Cadastro* cad = guarda_cad(n);
	for(i=0; i<n; i++){
		printf("Qual o nome da %d� pessoa:\n", i+1);
		getchar();
		gets(name);
		strcpy(cad[i].nome, name);
		printf("Qual a idade de %s:\n", *cad[i].nome);
		scanf("%d", &cad[i].idade);
		printf("Digite o nome da rua e o n�mero da casa em que %s mora:\n", *cad[i].nome);
		getchar();
		gets(cad[i].endereco.rua);
		scanf("%d", &cad[i].endereco.numero);
	}
	for(i=0; i<n; i++){
		printf("%s, %d anos, mora na rua %s n�mero %d.\n", cad[i].nome, cad[i].idade, cad[i].endereco.rua, cad[i].endereco.numero);
	}
	return 0;
}
