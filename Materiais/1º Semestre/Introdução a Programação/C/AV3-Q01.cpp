#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
	int codigo;
	char nome[50];
	int partidas[10];
	int gols_feitos;
	int gols_sofridos;
}Time;

Time preenche_time(int codigo, char nome[50], int a_1, int a_2, int a_3, int a_4, int a_5, int a_6, int a_7, int a_8, int a_9, int a_10, int gols_feitos, int gols_sofridos){
	Time t;
	t.codigo=codigo;
	strcpy(t.nome, nome);
	t.partidas[0]=a_1;
	t.partidas[1]=a_2;
	t.partidas[2]=a_3;
	t.partidas[3]=a_4;
	t.partidas[4]=a_5;
	t.partidas[5]=a_6;
	t.partidas[6]=a_7;
	t.partidas[7]=a_8;
	t.partidas[8]=a_9;
	t.partidas[9]=a_10;
	t.gols_feitos=gols_feitos;
	t.gols_sofridos=gols_sofridos;
	return t;
}

int pior_time(Time times[], int n){
	int maior=times[0].gols_sofridos, codigo=times[0].codigo;
	for(int i=1; i<n; i++){
		if(times[i].gols_sofridos>maior){
			maior=times[i].gols_sofridos;
			codigo=times[i].codigo;
		}
	}
	return codigo;
}

int pontos(Time time){
	int pontos=0;
	for(int i=0; i<10; i++){
		if(time.partidas[i]==1){
			pontos+=3;
		}else if(time.partidas[i]==0){
			pontos+=1;
		}
	}
	return pontos;
}

int maior_pontuador(Time times[], int n){
	int codigo=times[0].codigo, maior=pontos(times[0]);
	for(int i=1; i<n; i++){
		if(pontos(times[i])>maior){
			maior=pontos(times[i]);
			codigo=times[i].codigo;
		}
	}
	return codigo;
}

int saldo_de_gols(Time time){
	int saldo=time.gols_feitos-time.gols_sofridos;
	if(saldo>0){
		return 1;
	}else{
		return 0;
	}
}

int qtd_positivo(Time times[], int n){
	int contador=0;
	for(int i=0; i<n; i++){
		if(saldo_de_gols(times[i])==1){
			contador++;
		}
	}
	return contador;
}

int* tabela_positivo(Time times[], int n){
	int qtd=qtd_positivo(times, n);
	int* tabela=(int*)malloc(qtd*sizeof(int));
	int index=0;
	for(int i=0; i<n; i++){
		if(saldo_de_gols(times[i])==1){
			tabela[index]=times[i].codigo;
			index++;
		}
	}
	return tabela;
}

int ganhou_3(Time time){
	for(int i=0; i<8; i++){
		if((time.partidas[i]==1)&&(time.partidas[i+1]==1)&&(time.partidas[i+2]==1)){
			return 1;
		}
	}
	return 0;
}

void imprime_ganhadores(Time times[], int n){
	for(int i=0; i<n; i++){
		if(ganhou_3(times[i])==1){
			printf("%s \n", times[i].nome);
		}
	}
}

int main(){
	setlocale(LC_ALL, "portuguese");
	Time times[4];
	times[0]=preenche_time(1,"Flamengo", 1,1,0,-1,1,1,1,-1,-1,1,22,8);
	times[1]=preenche_time(2,"Vasco", 1,1,0,0,1,0,0,-1,-1,1,10,20);
	times[2]=preenche_time(3,"Botafogo", 0,1,0,0,-1,1,1,-1,-1,1,15,10);
	times[3]=preenche_time(4,"Fluminense", -1,-1,0,0,1,1,1,-1,-1,0,13,15);
	printf("Resultado dos times cariocas nas 10 primeiras rodadas do Brasileirão: \n\n");
	for(int i=0; i<4; i++){
		printf("%s: \n", times[i].nome);
		for(int j=0; j<10; j++){
			switch(times[i].partidas[j]){
				case -1: printf("Partida %d: Derrota \n", j+1); break;
				case 0: printf("Partida %d: Empate \n", j+1); break;
				case 1: printf("Partida %d: Vitória \n", j+1); break;
			}
		}
		printf("Quantidade de gols feitos: %d \n", times[i].gols_feitos);
		printf("Quantidade de gols sofridos: %d \n", times[i].gols_sofridos);
		printf("Quantidade de pontos: %d \n", pontos(times[i]));
		printf("\n");
	}
	int* tabela=tabela_positivo(times, 4);
	int qtd=qtd_positivo(times, 4);
	printf("Dentres os 4 times apenas: \n");
	for(int i=0; i<qtd; i++){
		switch(tabela[i]){
			case 1: printf("Flamengo \n"); break;
			case 2: printf("Vasco \n"); break;
			case 3: printf("Botafogo \n"); break;
			case 4: printf("Fluminense \n"); break;
		}
	}
	free(tabela);
	tabela=NULL;
	printf("Obtiveram saldo de gols positivo. \n");
	printf("Os times: \n");
	imprime_ganhadores(times, 4);
	printf("Ganharam três partidas consecutivas!!");
	return 0;
}
