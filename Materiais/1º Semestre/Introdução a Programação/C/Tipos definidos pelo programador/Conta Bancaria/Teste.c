#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaConta.h"

int main(){
	Lista* li = cria_lista();
	Cliente c[5];
	strcpy(c[0].nome, "Wanderson");
	strcpy(c[1].nome, "Thayná");
	strcpy(c[2].nome, "Marcio");
	strcpy(c[3].nome, "Neide");
	strcpy(c[4].nome, "Eduardo");
	int i;
	srand(time(NULL));
	for(i = 0; i<5; i++){
		c[i].conta = 100*(5-i);
		c[i].saldo = 100*(rand()%5+1);
		insere_conta(li, c[i]);
	}
	imprime_lista(li);
	printf("%d\n", tamanho_lista(li));
	remove_conta(li, 200);
	imprime_lista(li);
	printf("%d\n", tamanho_lista(li));
	printf("%d\n", busca_conta(li, 400));
	libera_lista(li);
	return 0;
}
