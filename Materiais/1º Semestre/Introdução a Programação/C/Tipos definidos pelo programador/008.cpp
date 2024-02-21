#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

typedef struct{
	int dia;
	int mes;
	int ano;
}Data;

typedef struct{
	char nome[100];
	Data data;
}Pessoa;

int conv_idade(Pessoa p){
	int idade = 0;
	idade += 365*(2022-p.data.ano);
	switch(p.data.mes){
		case 1: idade += 31*(12-p.data.mes); break;
		case 2: idade += 28*(12-p.data.mes); break;
		case 3: idade += 31*(12-p.data.mes); break;
		case 4: idade += 30*(12-p.data.mes); break;
		case 5: idade += 31*(12-p.data.mes); break;
		case 6: idade += 30*(12-p.data.mes); break;
		case 7: idade += 31*(12-p.data.mes); break;
		case 8: idade += 31*(12-p.data.mes); break;
		case 9: idade += 30*(12-p.data.mes); break;
		case 10: idade += 31*(12-p.data.mes); break;
		case 11: idade += 30*(12-p.data.mes); break;
		case 12: idade += 31*(12-p.data.mes); break;
	}
	idade += 31-p.data.dia;
	return idade;
}

void imprime_mais_velho(Pessoa p[], int n){
	Pessoa *maior = &p[0];
	int maior_idade = conv_idade(p[0]);
	for(int i=1; i<n; i++){
		if(conv_idade(p[i])>maior_idade){
			maior = &p[i];
			maior_idade = conv_idade(p[i]);
		}
	}
	printf("A pessoa mais velha é %s. Ela nasceu em %d/%d/%d.\n", maior->nome, maior->data.dia, maior->data.mes, maior->data.ano);
}

int main(){
	setlocale(LC_ALL, "portuguese");
	Pessoa p[4] = {{"Wanderson",{13,06,2022}},{"Neide",{02,12,1976}},{"Eduardo",{28,11,1998}},{"João",{01,12,1976}}};
	imprime_mais_velho(p, 4);
	return 0;
}
