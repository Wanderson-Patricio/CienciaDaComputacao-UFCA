#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
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
			printf("Esta rodada � do jogador %d.\n", jogador);
			printf("Escolha uma linha: ");
			scanf("%d", &linha);
			printf("Escolha uma coluna: ");
			scanf("%d", &coluna);

			/*Verificando se a jogada � v�lida*/

			while((m[linha-1][3*coluna-2]!=' ')){
				printf("Posi��o j� preenchida. Escolha outra posi��o.");
				printf("\n");
				printf("Esta rodada � do jogador %d.\n", jogador);
				printf("Escolha uma linha: ");
				scanf("%d", &linha);
				printf("Escolha uma coluna: ");
				scanf("%d", &coluna);
			}
			while((linha<1)||(linha>3)||(coluna<1)||(coluna>3)){
				printf("Posi��o inv�lida. Escolha outra posi��o.");
				printf("\n");
				printf("Esta rodada � do jogador %d.\n", jogador);
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
		printf("Voc� quer jogar de novo? \n s - sim \n n - n�o \n");
		scanf("%c", &verificador);
		while((verificador!='s')&&(verificador!='n')){
            system("cls");
			printf("Digite uma op��o v�lida: \n");
			scanf("%c", &verificador);
		}
		if(verificador=='n'){
			return 0;
		}
	}while(verificador=='s');
}
