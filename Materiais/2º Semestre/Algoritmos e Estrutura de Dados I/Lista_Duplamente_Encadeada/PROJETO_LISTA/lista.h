#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/******************************************Wanderson Faustino Patricio************************************************************/
/******************************************Ciência da Computação******************************************************************/
/******************************************UFCA - 2022.2**************************************************************************/

#define MAX_SIZE 1000

typedef struct node{
    char nome[50];
    int data;
    struct node* prev;
    struct node* next;
}Node;

// Retorna o tamanho atual da lista
int sizeOfLista(struct node** head);

//Diz se a lista está cheia
int isFull(struct node** head);

//Diz se a lista está vazia
int isEmpty(struct node** head);

//Insere ordenadamente dentro de uma lista
void inserir(struct node** head, char *nome ,int data);

//Remove o nó da lista
void removeNode(struct node** head, struct node* node);

//Limpa toda a lista
void clearList(struct node** head);

//Algoritmo de busca na lista
struct node* searchNode(struct node* head, char *nome);

//Exibe toda a lista
void displayList(struct node* head, char *operacao);

//Exibe a chave do nó
displayData(struct node* head, char* operacao);

//Exibe o nome e qual chave (operação) foi escolhida
void displayNode(struct node* head, char* operacao);

//Exibe o ultimo da lista
void displayLastNode(struct node* head, char* operacao);

//Inicializa 3 listas: uma para a média, uma para a matrícula e uma para o semestre
//E exibe opções do que o usuário pode fazer
void inicializar();

#endif // LISTA_H_INCLUDED
