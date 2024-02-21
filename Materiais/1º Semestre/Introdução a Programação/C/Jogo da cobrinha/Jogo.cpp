#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "functions.h"

int main(){
	setlocale(LC_ALL, "portuguese");
	int derrota, comidas_comidas;
	int** tab;
	Position inicial;
	int verificador = 1;
	while(verificador == 1){
		tab = cria_tabuleiro();
		inicial = posicao();
		tab[inicial.linha][inicial.coluna] = 1;
		comidas_comidas = 0;
		derrota = 1;
		while(derrota != -1){
			comida(tab);
			imprime_tab(tab);
			derrota--;
			system("pause");
			system("cls");
		}
		apagar(tab);
		printf("Você quer Jogar novamente?\n Sim - Digte 1\n Não - Digite qualquer outro número\n");
		scanf("%d", &verificador);
		system("cls");
	}
	printf("Obrigado por jogar o nosso Jogo! :):)\n");
	return 0;
}
