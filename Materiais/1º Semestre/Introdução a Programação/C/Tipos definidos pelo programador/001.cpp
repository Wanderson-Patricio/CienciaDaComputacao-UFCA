#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
	char nome[100];
	int idade;
	char endereco[100];
	int numero;
}Cadastro;

int main(){
	setlocale(LC_ALL, "portuguese");
	Cadastro cad={"Wanderson Faustino Patricio", 20, "S�tio Tabocas", 0};
	printf("%s de %d anos mora na rua %s n�mero %d.", cad.nome, cad.idade, cad.endereco, cad.numero);
	return 0;
}
