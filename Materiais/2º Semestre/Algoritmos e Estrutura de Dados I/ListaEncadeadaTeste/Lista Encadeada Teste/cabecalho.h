#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED

#define MAX_SIZE 1000

typedef struct node Node; //
typedef struct lista Lista;//

Lista* criarLista();//
Node* criarNo(int x);//

Node* busca(Lista* li, int x);//

void imprimeLista(Lista* li);//

void insereItem(Lista* li, int x);//

void removeItem(Lista* li, int x);

int tamanhoLista(Lista* li);//

void LiberaNo(Node* no);//
void esvaziaLista(Lista* li);//

int listaCheia(Lista* li);//
int listaVazia(Lista* li);//


#endif // CABECALHO_H_INCLUDED
