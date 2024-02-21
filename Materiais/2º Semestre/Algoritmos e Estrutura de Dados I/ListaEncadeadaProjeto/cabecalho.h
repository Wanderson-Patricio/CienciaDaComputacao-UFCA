#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED

#define MAX_SIZE 100

typedef struct cidade{
    char nome[100];
    float Temp;
    int Altitude;
    int populacao;
}Cidade;

typedef struct lista Lista;
typedef struct node Node;

Lista* criarLista();
Node* criarNo(Cidade city);
Cidade criarCidade(char* nome, float temp_media, int altitude, int populacao);

Node* buscaCidade(Lista* li, char* nome);

void imprimeCidade(Cidade city);
void imprimeListaPopulacao(Lista* li);
void imprimeListaAltitude(Lista* li);
void imprimeListaTemp(Lista* li);

void insereCidade(Lista* li, Node* novo);
void insereCidadePopulacao(Lista* li, Node* novo);
void insereCidadeTemp(Lista* li, Node* novo);
void insereCidadeAltitude(Lista* li, Node* novo);

void removeCidade(Lista* li, char* nome);
void removeCidadePopulacao(Lista* li, Node* aux);
void removeCidadeTemp(Lista* li, Node* aux);
void removeCidadeAltitude(Lista* li, Node* aux);

int tamanhoLista(Lista* li);

void LiberaNo(Node* no);
void esvaziaLista(Lista* li);

int listaCheia(Lista* li);
int listaVazia(Lista* li);

void inicializaListaCapitais(Lista* li);

#endif // CABECALHO_H_INCLUDED
