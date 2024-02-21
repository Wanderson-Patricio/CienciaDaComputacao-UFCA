#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "tabuleiro.h"

int main(){
	setlocale(LC_ALL, "portuguese");
	char coluna_letra;
	int verificador = 1;
	int turno, jogadas_restantes, vitoria, acertos, i, j, linha, coluna;
	int **tabuleiro, **tabuleiro_aux;
	srand(time(NULL));
	while(verificador == 1){
		turno = 1;
		jogadas_restantes = 20;
		vitoria = 0;
		acertos = 0;
		tabuleiro = cria_tabuleiro();
		preenche_tabuleiro(tabuleiro, 0);
		tabuleiro_aux = cria_tabuleiro();
		preenche_tabuleiro(tabuleiro_aux, 2);
		for(i=0; i<5; i++){
			do{
				linha = rand() % 5;
				coluna = rand() % 5;
			}while(tabuleiro[linha][coluna] != 0);
			tabuleiro[linha][coluna] = 1;
		}
		while((turno <= 20)&&(vitoria == 0)){
			imprime(tabuleiro_aux);
			printf(" Faltam %d jogadas \n Faltam %d navios. \n", jogadas_restantes, 5-acertos);
			do{
				printf("Escolha uma posição >> ");
				scanf("%c %d", &coluna_letra, &linha);
				switch(coluna_letra){
					case 'a': coluna = 1; break;
					case 'b': coluna = 2; break;
					case 'c': coluna = 3; break;
					case 'd': coluna = 4; break;
					case 'e': coluna = 5; break;
				}
			}while((linha<1)||(linha>5)||(coluna<1)||(coluna>5)||(tabuleiro_aux[linha-1][coluna-1] != 2));
			tabuleiro_aux[linha-1][coluna-1] = tabuleiro[linha-1][coluna-1];
			system("cls");
			imprime(tabuleiro_aux);
			if(tabuleiro[linha-1][coluna-1] == 0){
				printf("Você não acertou nenhum navio. \n");
			}else{
				printf("Você acertou um navio. \n");
				acertos++;
			}
			vitoria = cond_vit(acertos);
			system("pause");
			system("cls");
			turno++;
			jogadas_restantes--;
		}
		imprime(tabuleiro);
		apagar(tabuleiro);
		apagar(tabuleiro_aux);
		if(vitoria == 1){
			printf("Você ganhou a partida :) !! \n");
		}else{
			printf("Você perdeu a partida :( \n");
		}
		printf("Você quer jogar novamente? \nSim - Digite 1 \nNão - Digite qualquer outro número \n");
		scanf("%d", &verificador);
		system("cls");
	}
	return 0;
}
