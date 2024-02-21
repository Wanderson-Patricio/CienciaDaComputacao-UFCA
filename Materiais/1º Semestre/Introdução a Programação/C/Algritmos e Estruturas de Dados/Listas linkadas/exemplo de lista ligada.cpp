#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

// Definindo o tipo de Cadastro que será salvo na lista
typedef struct{
	int conta;
	float saldo;
}Cadastro;

// Definindo a lista ligada
struct list{
	Cadastro data;
	struct list *next;
};

// Procedimento para inserir um elemento(novo) na lista com primeiro elemento first
void insert(struct list *novo, struct list *first){
	if(first == NULL){
		first->data = novo->data;
		first->next = NULL;
	}else if(first->next == NULL){
		first->next = novo;
		novo->next = NULL;
	}else if(first->next->data.conta >= novo->data.conta){
		novo->next = first->next;
		first->next = novo;
	}else{
		insert(novo,first->next);
	}
}

// Procedimento para imprimir uma lista linkada
void printList(struct list *first){
	if(first == NULL){
		printf("A lista é vazia !!");
	}else{
		printf("Número da conta: %d \n", first->data.conta);
		printf("Saldo: R$%.2f \n", first->data.saldo);
		printf("\n");
		if(first->next != NULL){
			printList(first->next);
		}
	}
}

// Função que retorna um ponteiro para um elemento chave na lista
struct list* search(int chave, struct list *first){
	if(first->data.conta == chave){
		return first;
	}else if(first->next == NULL){
		return NULL;	
	}else{
		search(chave, first->next);
	}
}

// Função para achar o elemento anterior ao apontado
struct list* searchPrevious(int chave, struct list *first){
	if(first->next->data.conta == chave){
		return first;
	}else if(first->next == NULL){
		return NULL;
	}else{
		searchPrevious(chave,first->next);
	}
}

// Procedimento para liberar o espaço na memória heap
void liberar(struct list *elemento){
	free(elemento);
	elemento = NULL;
}

// Procedimento para remover um elemento da lista
void remove(int chave, struct list *first){
	struct list *pont1 = search(chave, first);
	struct list *pont2;
	if(pont1 != NULL){
		pont2 = searchPrevious(chave, first);
		pont2->next = pont1->next;
		pont1->next = NULL;
	}
}
// Função para contar o tamanho de uma lista
int listLength(struct list *first){
	if(first->next == NULL){
		return 1;
	}else{
		return 1 + listLength(first->next);
	}
}

// Função Main
int main(){
	setlocale(LC_ALL, "portuguese");
	
	// Até a linha 121 será criado uma lista linkada pré definida
	int n = 100;
	struct list first, conj[n];
	first.data.conta = 0;
	first.data.saldo = 0.00;
	first.next = NULL;
	for(int i = 0; i<n; i++){
		conj[i].data.conta = n-i;
		conj[i].data.saldo = (float) 100*i;
	}
	for(int i = 0; i<n; i++){
		insert(&conj[i], &first);
	}
	
	// A partir desta linha será criada as opções para o usuário
	struct list *vet = (struct list*) malloc(100*sizeof(struct list));
	int op = 1, option, conta, contador = 0;
	float saldo;
	struct list *aux;
	while(op == 1){
		printf("O que você deseja fazer?\n");
		printf("1 - Imprimir a lista\n");
		printf("2 - Criar um novo elemento\n");
		printf("3 - Imprimir os dados de uma conta\n");
		printf("4 - Excluir um elemento\n");
		printf("5 - Sair do programa\n");
		scanf("%d", &option);
		system("cls");
		switch(option){
			case 1:{
				printList(&first);
				break;
			}
			case 2:{
				printf("Qual o saldo da nova conta?\n");
				scanf("%f", &saldo);
				vet[contador].data.conta = listLength(&first);
				vet[contador].data.saldo = saldo;
				insert(vet+contador, &first);
				contador++;
				system("cls");
				printf("O novo elemento foi criado.\n");
				break;
			}
			case 3:{
				printf("Qual o número da conta?\n");
				scanf("%d", &conta);
				if(conta >= listLength(&first)){
					printf("Não existe essa conta na lista.\n");
				}else{
					aux = search(conta, &first);
					system("cls");
					printf("Número da conta: %d \n", aux->data.conta);
					printf("Saldo da conta: %.2f \n", aux->data.saldo);
				}
				break;
			}
			case 4:{
				printf("Qual o número da conta a ser excluída?\n");
				scanf("%d", &conta);
				if(conta > listLength(&first)){
					printf("Não existe essa conta na lista.\n");
				}else{
					remove(conta, &first);
					system("cls");
					printf("O elemento foi excluído da lista.\n");
				}
				break;
			}
			case 5:{
				op = 0;
				break;
			}
		}
		system("pause");
		system("cls");
	}
	system("cls");
	printf("Obrigado por usar nosso programa :):)\n");
	return 0;
}
