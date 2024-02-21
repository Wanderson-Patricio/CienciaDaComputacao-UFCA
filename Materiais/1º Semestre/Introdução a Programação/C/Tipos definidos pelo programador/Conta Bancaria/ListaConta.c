#include <stdio.h>
#include <stdlib.h>
#include "ListaConta.h"
#include <string.h>

struct lista{
	int tam;
	Cliente clientes[MAX];
};

Lista* cria_lista(){
	Lista* li = (Lista*)malloc(sizeof(Lista));
	if(li != NULL){
		return li;
		li->tam = 0;
	}
}

void esvazia_lista(Lista* li){
	free(li);
	li = NULL;
}

int busca_conta(Lista* li, int chave){
	int index = -1;
	int i;
	for(i = 0; i<li->tam; i++){
		if(li->clientes[i].conta == chave){
			index = i;
			break;
		}
	}
	return index;
}

int tamanho_lista(Lista* li){
	return li->tam;
}

void imprime_lista(Lista* li){
	int i;
	for(i=0; i<tamanho_lista(li); i++){
		printf("Nome do cliente: %s \nNúmero da Conta: %d\nSaldo: R$%.2f \n\n", li->clientes[i].nome, li->clientes[i].conta, li->clientes[i].saldo);
	}
}

void insere_conta(Lista* li, Cliente novo){
	if(tamanho_lista(li)<MAX){
		li->clientes[li->tam] = novo;
		li->tam++;
	}else{
		printf("A lista está cheia.\n");
	}
}

void remove_conta(Lista* li, int chave){
	if(busca_conta(li, chave) == -1){
		printf("Não existe essa conta na lista.\n");
	}else{
		int i;
		for(i = busca_conta(li, chave); i<tamanho_lista(li)-1; i++){
			li->clientes[i] = li->clientes[i+1];
		}
		li->tam--;
	}
}
