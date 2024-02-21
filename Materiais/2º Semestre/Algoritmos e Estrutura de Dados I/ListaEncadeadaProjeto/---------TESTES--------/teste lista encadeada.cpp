#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node* next;
    struct node* prev;
}Node;

typedef struct lista{
    Node* first;
    Node* last;
    int tamanho;
}Lista;

Node* criarNo(int key){
    Node* aux = (Node*)malloc(sizeof(Node));
    aux->key = key;
    aux->next = NULL;
    aux->prev = NULL;
    return aux;
}

Lista* criarLista(){
    Lista* aux = (Lista*)malloc(sizeof(Lista));
    aux->first = NULL;
    aux->last = NULL;
    aux->tamanho = 0;
    return aux;
}

void imprimeLista(Lista* li){
    if(li->tamanho != 0){
        Node *aux = li->first;
        printf("Em ordem crescente temos: \n");
        while(aux != NULL){
            printf("%d \n", aux->key);
            aux  = aux->next;
        }
    }else{
        printf("A lista está vazia.\n");
    }
}

void insereNo(Lista* li, Node* novo){
    if(li->tamanho == 1000){

        printf("A lista já está cheia. \n");

    }else{

        if(li->tamanho == 0){

            li->first = novo;
            li->last = novo;

        }else if(li->first->key > novo->key){

            novo->next = li->first;
            li->first->prev = novo;
            li->first = novo;

        }else{

            Node* aux = li->first;
            while(aux != NULL && aux->key <= novo->key){
                aux = aux->next;
            }

            if(aux == NULL){
                li->last->next = novo;
                novo->prev = li->last;
                li->last = novo;
            }else{

                novo->next = aux;
                novo->prev = aux->prev;
                aux->prev->next =novo;
                aux->prev = novo;

            }
        }
    }
    
    li->tamanho++;
}

int main(){
	Lista* li = criarLista();
	
	
	for(int i = 100; i>0; i--){
		insereNo(li, criarNo(i));
	}
	
	imprimeLista(li);
	return 0;
}
