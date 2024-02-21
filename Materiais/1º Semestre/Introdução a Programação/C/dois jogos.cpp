#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "tabuleiro.h"

void batalha_naval(){
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
}

void jogo_da_velha(){
	setlocale(LC_ALL, "portuguese");
	int jogada, jogador, vitoria, linha, coluna, i, j;
	char m[3][9];
	char verificador;
	do{
		system("cls");
		jogada=1; vitoria=0; jogador=1;
		char m[3][9]={'[',' ',']','[',' ',']','[',' ',']','[',' ',']','[',' ',']','[',' ',']','[',' ',']','[',' ',']','[',' ',']'};
		while((jogada<=8)&&(vitoria==0)){
			/*Imprimir o jogo na tela*/
			for(i=0; i<3; i++){
				printf("\n");
				for(j=0; j<9; j++){
					printf("%c", m[i][j]);
				}
			}

			/*Computar a jogada do jogador*/

			printf("\n");
			printf("Esta rodada é do jogador %d.\n", jogador);
			printf("Escolha uma linha: ");
			scanf("%d", &linha);
			printf("Escolha uma coluna: ");
			scanf("%d", &coluna);

			/*Verificando se a jogada é válida*/

			while((m[linha-1][3*coluna-2]!=' ')){
				printf("Posição já preenchida. Escolha outra posição.");
				printf("\n");
				printf("Esta rodada é do jogador %d.\n", jogador);
				printf("Escolha uma linha: ");
				scanf("%d", &linha);
				printf("Escolha uma coluna: ");
				scanf("%d", &coluna);
			}
			while((linha<1)||(linha>3)||(coluna<1)||(coluna>3)){
				printf("Posição inválida. Escolha outra posição.");
				printf("\n");
				printf("Esta rodada é do jogador %d.\n", jogador);
				printf("Escolha uma linha: ");
				scanf("%d", &linha);
				printf("Escolha uma coluna: ");
				scanf("%d", &coluna);
			}

			/*Executando a jogada*/

			if(jogador==1){
				m[linha-1][3*coluna-2]='X';
				jogador=2;
			}else{
				m[linha-1][3*coluna-2]='O';
				jogador=1;
			}

			/*Verificando se o jogador venceu*/

			if((m[0][1]=='X')&&(m[0][4]=='X')&&(m[0][7]=='X')){
				vitoria=1;
			}else if((m[1][1]=='X')&&(m[1][4]=='X')&&(m[1][7]=='X')){
				vitoria=1;
			}else if((m[2][1]=='X')&&(m[2][4]=='X')&&(m[2][7]=='X')){
				vitoria=1;
			}else if((m[0][1]=='X')&&(m[1][1]=='X')&&(m[2][1]=='X')){
				vitoria=1;
			}else if((m[0][4]=='X')&&(m[1][4]=='X')&&(m[2][4]=='X')){
				vitoria=1;
			}else if((m[0][7]=='X')&&(m[1][7]=='X')&&(m[2][7]=='X')){
				vitoria=1;
			}else if((m[0][1]=='X')&&(m[1][4]=='X')&&(m[2][7]=='X')){
				vitoria=1;
			}else if((m[2][1]=='X')&&(m[1][4]=='X')&&(m[0][7]=='X')){
				vitoria=1;
			}else if((m[0][1]=='O')&&(m[0][4]=='O')&&(m[0][7]=='O')){
				vitoria=1;
			}else if((m[1][1]=='O')&&(m[1][4]=='O')&&(m[1][7]=='O')){
				vitoria=1;
			}else if((m[2][1]=='O')&&(m[2][4]=='O')&&(m[2][7]=='O')){
				vitoria=1;
			}else if((m[0][1]=='O')&&(m[1][1]=='O')&&(m[2][1]=='O')){
				vitoria=1;
			}else if((m[0][4]=='O')&&(m[1][4]=='O')&&(m[2][4]=='O')){
				vitoria=1;
			}else if((m[0][7]=='O')&&(m[1][7]=='O')&&(m[2][7]=='O')){
				vitoria=1;
			}else if((m[0][1]=='O')&&(m[1][4]=='O')&&(m[2][7]=='O')){
				vitoria=1;
			}else if((m[2][1]=='O')&&(m[1][4]=='O')&&(m[0][7]=='O')){
				vitoria=1;
			}
			jogada++;
			system("cls");
		}
		if(jogada==9){
			for(i=0; i<3; i++){
				for(j=0; j<9; j++){
					if(m[i][j]==' '){
						if(jogador==1){
							m[i][j]='X';
							jogador=2;
						}else{
							m[i][j]='O';
							jogador=1;
						}
					}
				}
			}
		}
		if((m[0][1]=='X')&&(m[0][4]=='X')&&(m[0][7]=='X')){
			vitoria=1;
		}else if((m[1][1]=='X')&&(m[1][4]=='X')&&(m[1][7]=='X')){
			vitoria=1;
		}else if((m[2][1]=='X')&&(m[2][4]=='X')&&(m[2][7]=='X')){
			vitoria=1;
		}else if((m[0][1]=='X')&&(m[1][1]=='X')&&(m[2][1]=='X')){
			vitoria=1;
		}else if((m[0][4]=='X')&&(m[1][4]=='X')&&(m[2][4]=='X')){
			vitoria=1;
		}else if((m[0][7]=='X')&&(m[1][7]=='X')&&(m[2][7]=='X')){
			vitoria=1;
		}else if((m[0][1]=='X')&&(m[1][4]=='X')&&(m[2][7]=='X')){
			vitoria=1;
		}else if((m[2][1]=='X')&&(m[1][4]=='X')&&(m[0][7]=='X')){
			vitoria=1;
		}else if((m[0][1]=='O')&&(m[0][4]=='O')&&(m[0][7]=='O')){
			vitoria=1;
		}else if((m[1][1]=='O')&&(m[1][4]=='O')&&(m[1][7]=='O')){
			vitoria=1;
		}else if((m[2][1]=='O')&&(m[2][4]=='O')&&(m[2][7]=='O')){
			vitoria=1;
		}else if((m[0][1]=='O')&&(m[1][1]=='O')&&(m[2][1]=='O')){
			vitoria=1;
		}else if((m[0][4]=='O')&&(m[1][4]=='O')&&(m[2][4]=='O')){
			vitoria=1;
		}else if((m[0][7]=='O')&&(m[1][7]=='O')&&(m[2][7]=='O')){
			vitoria=1;
		}else if((m[0][1]=='O')&&(m[1][4]=='O')&&(m[2][7]=='O')){
			vitoria=1;
		}else if((m[2][1]=='O')&&(m[1][4]=='O')&&(m[0][7]=='O')){
			vitoria=1;
		}
		for(i=0; i<3; i++){
			printf("\n");
			for(j=0; j<9; j++){
				printf("%c", m[i][j]);
			}
		}
		printf("\n");
		if(vitoria==0){
			printf("O jogo deu velha.");
		}else{
			if(jogada%2==0){
				printf("O jogador 1 venceu.");
			}else{
				printf("O jogador 2 venceu.");
			}
		}
		printf("\n");
		printf("Você quer jogar de novo? \n s - sim \n n - não \n");
		scanf("%c", &verificador);
		while((verificador!='s')&&(verificador!='n')){
			printf("Digite uma opção válida: \n");
			scanf("%c", &verificador);
		}
	}while(verificador=='s');
}

int main(){
	int op = -1;
	while(op != 0){
		system("cls");
		do{
			printf("Escolha um jogo: \n Jogo Da Velha - Digite 1\n Batalha Naval - Digite 2 \n Sair - Digite 0 \n");
			scanf("%d", &op);
		}while((op != 0)&&(op != 1)&&(op != 2));
		system("cls");
		switch(op){
			case 1: jogo_da_velha(); break;
			case 2: batalha_naval(); break;
		}
	}
	system("cls");
	printf("Obrigado por Utilizar nossa plataforma :):)");
	return 0;
}
