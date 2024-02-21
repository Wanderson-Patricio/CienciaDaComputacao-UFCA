#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabecalho.h"

/********************************************************************************/
/*******************Definição de Estruturas**************************************/

typedef struct node{
    Cidade city;
    Node* nextPopulacao;
    Node* prevPopulacao;
    Node* nextAltitude;
    Node* prevAltitude;
    Node* nextTemp;
    Node* prevTemp;
}Node;

typedef struct lista{
    Node* firstPopulacao;
    Node* lastPopulacao;
    Node* firstAltitude;
    Node* lastAltitude;
    Node* firstTemp;
    Node* lastTemp;
    int tamanho;
}Lista;

/********************************************************************************/
/*******************Criação de Estruturas****************************************/

Lista* criarLista(){
    Lista* aux = (Lista*)malloc(sizeof(Lista));
    aux->firstAltitude = NULL;
    aux->lastAltitude = NULL;
    aux->firstPopulacao = NULL;
    aux->lastPopulacao = NULL;
    aux->firstTemp = NULL;
    aux->lastTemp = NULL;
    aux->tamanho = 0;
    return aux;
}

Node* criarNo(Cidade city){
    Node* aux = (Node*)malloc(sizeof(Node));
    aux->city = city;
    aux->nextAltitude = NULL;
    aux->prevAltitude = NULL;
    aux->nextPopulacao = NULL;
    aux->prevPopulacao = NULL;
    aux->nextTemp = NULL;
    aux->prevTemp = NULL;
    return aux;
}

Cidade criarCidade(char* nome, float temp_media, int populacao, int altitude){
    Cidade aux;
    aux.Altitude = altitude;
    aux.populacao = populacao;
    aux.Temp = temp_media;
    strcpy(aux.nome, nome);
    return aux;
}

/********************************************************************************/
/*******************Imprimindo na tela*******************************************/



void imprimeCidade(Cidade city){
    printf("%s \n\n população: %d habitantes \n altitude: %d m \n Temperatura média: %.2f ºC \n\n", city.nome, city.populacao, city.Altitude, city.Temp);
}

void imprimeListaPopulacao(Lista* li){
    if(listaVazia(li) != 1){
        Node *aux = (Node*)malloc(sizeof(Node));
        aux = li->firstPopulacao;
        printf("Em ordem crescente de população temos: \n");
        while(aux != NULL){
            imprimeCidade(aux->city);
            aux  = aux->nextPopulacao;
        }
        free(aux);
    }else{
        printf("A lista está vazia.\n");
    }
}

void imprimeListaAltitude(Lista* li){
    if(listaVazia(li) != 1){
        Node *aux = (Node*)malloc(sizeof(Node));
        aux = li->firstAltitude;
        printf("Em ordem crescente de altitude temos: \n");
        while(aux != NULL){
            imprimeCidade(aux->city);
            aux  = aux->nextAltitude;
        }
        free(aux);
    }else{
        printf("A lista está vazia.\n");
    }
}

void imprimeListaTemp(Lista* li){
    if(listaVazia(li) != 1){
        Node *aux = (Node*)malloc(sizeof(Node));
        aux = li->firstTemp;
        printf("Em ordem crescente de altitude temos: \n");
        while(aux != NULL){
            imprimeCidade(aux->city);
            aux  = aux->nextTemp;
        }
        free(aux);
    }else{
        printf("A lista está vazia.\n");
    }
}

/********************************************************************************/
/*******************Busca de uma cidade******************************************/


Node* buscaCidade(Lista* li, char* nome){
    Node* aux = (Node*)malloc(sizeof(Node));
    aux = li->firstPopulacao;
    while(aux != NULL){
        if(strcmp(aux->city.nome, nome) == 0){
            break;
        }
    }

    return aux;
}


/********************************************************************************/
/*******************Inserção de Cidades******************************************/



void insereCidade(Lista* li, Node* novo){
    if(buscaCidade(li, novo->city.nome) == NULL){
        insereCidadePopulacao(li, novo);
        insereCidadeAltitude(li, novo);
        insereCidadeTemp(li, novo);
        li->tamanho++;
    }else{
        printf("A cidade já foi inserida na lista.\n");
    }
}

void insereCidadePopulacao(Lista* li, Node* novo){
    if(listaCheia(li) == 1){

        printf("A lista já está cheia. \n");

    }else{

        if(listaVazia(li) == 1){

            li->firstPopulacao = novo;
            li->lastPopulacao = novo;

        }else if(li->firstPopulacao->city.populacao > novo->city.populacao){

            novo->nextPopulacao = li->firstPopulacao;
            li->firstPopulacao->prevPopulacao = novo;
            li->firstPopulacao = novo;

        }else{

            Node* aux = (Node*)malloc(sizeof(Node));
            aux = li->firstPopulacao;

            while(aux != NULL && aux->city.populacao <= novo->city.populacao){
                aux = aux->nextPopulacao;
            }

            if(aux == NULL){
                li->lastPopulacao->nextPopulacao = novo;
                novo->prevPopulacao = li->lastPopulacao;
                li->lastPopulacao = novo;
            }else{

                novo->nextPopulacao = aux;
                novo->prevPopulacao = aux->prevPopulacao;
                aux->prevPopulacao->nextPopulacao =novo;
                aux->prevPopulacao = novo;

            }

            free(aux);
        }
    }
}

void insereCidadeTemp(Lista* li, Node* novo){
    if(listaCheia(li) == 1){

        printf("A lista já está cheia. \n");

    }else{

        if(listaVazia(li) == 1){

            li->firstTemp = novo;
            li->lastTemp = novo;

        }else if(li->firstTemp->city.Temp > novo->city.Temp){

            novo->nextTemp = li->firstTemp;
            li->firstTemp->prevTemp = novo;
            li->firstTemp = novo;

        }else{

            Node* aux = (Node*)malloc(sizeof(Node));
            aux = li->firstTemp;
            while(aux != NULL && aux->city.Temp <= novo->city.Temp){
                aux = aux->nextTemp;
            }

            if(aux == NULL){
                li->lastTemp->nextTemp = novo;
                novo->prevTemp = li->lastTemp;
                li->lastTemp = novo;
            }else{

                novo->nextTemp = aux;
                novo->prevTemp = aux->prevTemp;
                aux->prevTemp->nextTemp =novo;
                aux->prevTemp = novo;

            }

            free(aux);
        }
    }
}

void insereCidadeAltitude(Lista* li, Node* novo){
    if(listaCheia(li) == 1){

        printf("A lista já está cheia. \n");

    }else{

        if(listaVazia(li) == 1){

            li->firstAltitude = novo;
            li->lastAltitude = novo;

        }else if(li->firstAltitude->city.Altitude > novo->city.Altitude){

            novo->nextAltitude = li->firstAltitude;
            li->firstAltitude->prevAltitude = novo;
            li->firstAltitude = novo;

        }else{

            Node* aux = (Node*)malloc(sizeof(Node));
            aux = li->firstAltitude;
            while(aux != NULL && aux->city.Altitude <= novo->city.Altitude){
                aux = aux->nextAltitude;
            }

            if(aux == NULL){
                li->lastAltitude->nextAltitude = novo;
                novo->prevAltitude = li->lastAltitude;
                li->lastAltitude = novo;
            }else{

                novo->nextAltitude = aux;
                novo->prevAltitude = aux->prevAltitude;
                aux->prevAltitude->nextAltitude =novo;
                aux->prevAltitude = novo;

            }

            free(aux);
        }
    }
}


/********************************************************************************/
/*******************Remoção de cidades*******************************************/


void removeCidade(Lista* li, char* nome){
    Node* aux = buscaCidade(li, nome);
    if(aux != NULL){
        removeCidadePopulacao(li, aux);
        removeCidadeAltitude(li, aux);
        removeCidadeTemp(li, aux);
        li->tamanho--;
    }else{
        printf("A cidade não está na lista.\n");
    }
}

void removeCidadePopulacao(Lista* li, Node* aux){
    aux->prevPopulacao->nextPopulacao = aux->nextPopulacao;
    if(aux->nextPopulacao != NULL){
        aux->nextPopulacao->prevPopulacao = aux->prevPopulacao;
    }
    LiberaNo(aux);
}

void removeCidadeAltitude(Lista* li, Node* aux){
    aux->prevAltitude->nextAltitude = aux->nextAltitude;
    if(aux->nextAltitude != NULL){
        aux->nextAltitude->prevAltitude = aux->prevAltitude;
    }
    LiberaNo(aux);
}

void removeCidadeTemp(Lista* li, Node* aux){
    aux->prevTemp->nextTemp = aux->nextTemp;
    if(aux->nextTemp != NULL){
        aux->nextTemp->prevTemp = aux->prevTemp;
    }
    LiberaNo(aux);
}


/********************************************************************************/
/*******************Acessa o tamanho atual da lista******************************/


int tamanhoLista(Lista* li){
    return li->tamanho;
}

/********************************************************************************/
/*******************Apaga a Lista************************************************/



void LiberaNo(Node* no){
    free(no);
    no = NULL;
}

void esvaziaLista(Lista* li){
    if(listaVazia(li) != 1){
        Node** vet = (Node**)malloc(MAX_SIZE*sizeof(Node*));
        int index = 0;
        Node* aux = (Node*)malloc(sizeof(Node));
        aux = li->firstAltitude;
        while(aux!=NULL){
            *(vet + index) = aux;
            index++;
            aux = aux->nextAltitude;
        }
        for(int i = 0; i<index; i++){
            LiberaNo(*(vet + i));
        }

        free(aux);
        free(vet);
        free(li);
        li = criarLista();
    }
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

/********************************************************************************/
/*******************Inserção das capitais****************************************/

void inicializaListaCapitais(Lista* li){
    insereCidade(li, criarNo(criarCidade("Aracaju", 27.3, 664908, 4)));
    insereCidade(li, criarNo(criarCidade("Belem", 26.4, 1499641, 10)));
    insereCidade(li, criarNo(criarCidade("Belo Horizonte", 22.5, 2521564, 852)));
    insereCidade(li, criarNo(criarCidade("Boa Vista", 28.1, 419652, 90)));
    insereCidade(li, criarNo(criarCidade("Brasilia", 20.5, 3055149, 1171)));
    insereCidade(li, criarNo(criarCidade("Campo Grande", 24.6, 906092, 592)));
    insereCidade(li, criarNo(criarCidade("Cuiaba", 26.8, 618124, 125)));
    insereCidade(li, criarNo(criarCidade("Curitiba", 20.4, 1948626, 934)));
    insereCidade(li, criarNo(criarCidade("Florianopolis", 24.5, 508826, 3)));
    insereCidade(li, criarNo(criarCidade("Fortaleza", 27.6, 2686612, 16)));
    insereCidade(li, criarNo(criarCidade("Goiania", 23.2, 1536097, 749)));
    insereCidade(li, criarNo(criarCidade("Joao Pessoa", 27.5, 817511, 40)));
    insereCidade(li, criarNo(criarCidade("Macapa", 26.5, 512902, 14)));
    insereCidade(li, criarNo(criarCidade("Maceio", 26.7, 1025360, 300)));
    insereCidade(li, criarNo(criarCidade("Manaus", 26.3, 2219580, 98)));
    insereCidade(li, criarNo(criarCidade("Natal", 27.3, 890480, 30)));
    insereCidade(li, criarNo(criarCidade("Palmas", 24.9, 306296, 280)));
    insereCidade(li, criarNo(criarCidade("Porto Alegre", 24.8, 1488252, 10)));
    insereCidade(li, criarNo(criarCidade("Porto Velho", 26.1, 539354, 85)));
    insereCidade(li, criarNo(criarCidade("Recife", 26.5, 1653461, 4)));
    insereCidade(li, criarNo(criarCidade("Rio de Janeiro", 26.6, 6747815, 153)));
    insereCidade(li, criarNo(criarCidade("Rio Branco", 25.2, 413418, 2)));
    insereCidade(li, criarNo(criarCidade("Salvador", 26.4, 2886698, 83)));
    insereCidade(li, criarNo(criarCidade("Sao Luis", 27.5, 1108975, 4)));
    insereCidade(li, criarNo(criarCidade("Sao Paulo", 21.5, 12325232, 760)));
    insereCidade(li, criarNo(criarCidade("Teresina", 27.2, 868075, 72)));
    insereCidade(li, criarNo(criarCidade("Vitoria", 25.8, 365855, 1)));
}
