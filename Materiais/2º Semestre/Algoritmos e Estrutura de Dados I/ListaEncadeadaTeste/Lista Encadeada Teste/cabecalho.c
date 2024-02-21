#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

typedef struct node{
    int chave;
    Node* next;
    Node* prev;
}Node;

typedef struct lista{
    Node* first;
    Node* last;
    int tamanho;
}Lista;

Node* criarNo(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->chave = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

Lista* criarLista(){
    Lista* temp = (Lista*)malloc(sizeof(Lista));
    temp->tamanho = 0;
    temp->first = NULL;
    temp->last = NULL;
    return temp;
}

void imprimeLista(Lista* li){
    Node* aux = li->first;
    while(aux != NULL){
        printf("%d \n", aux->chave);
        aux = aux->next;
    }
}

Node* busca(Lista* li, int x){
    Node* aux = li->first;
    while(aux != NULL){
        if(aux->chave == x){
            break;
        }
        aux = aux->next;
    }

    return aux;
}

void insereItem(Lista* li, int x){
    if(listaCheia(li) == 1){

        printf("A lista já está cheia. \n");

    }else{

        Node* novo = criarNo(x);

        if(listaVazia(li) == 1){

            li->first = novo;
            li->last = novo;

        }else if(li->first->chave > x){

            novo->next = li->first;
            li->first->prev = novo;
            li->first = novo;

        }else{

            Node* aux = li->first;
            while(aux != NULL && aux->chave <= x){
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

        li->tamanho ++;
    }
}

removeItem(Lista* li, int x){
    if(listaVazia(li) == 1){
        printf("A lista está vazia.\n");
    }else{

        Node* aux = busca(li, x);
        if(aux == NULL){
            printf("O elemento não está na lista.\n");
        }else{

            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            LiberaNo(aux);
            printf("Elemento removido.\n");

        }

    }
}



void esvaziaLista(Lista* li){
    Node* aux = li->first;
    Node* temp;
    while(aux != NULL){
        temp = aux->next;
        LiberaNo(aux);
        aux = temp;
    }

    free(li);
    li = NULL;
}

int tamanhoLista(Lista* li){
    return li->tamanho;
}

void LiberaNo(Node* no){
    free(no);
    no = NULL;
}

int listaCheia(Lista* li){
    int result = 0;
    if(li->tamanho == MAX_SIZE){
        result = 1;
    }
    return result;
}

int listaVazia(Lista* li){
    int result = 0;
    if(li->tamanho == 0){
        result = 1;
    }
    return result;
}
