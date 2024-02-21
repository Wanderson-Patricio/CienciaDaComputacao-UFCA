#ifndef LISTACONTA_H_INCLUDED
#define LISTACONTA_H_INCLUDED

#define MAX 1000

typedef struct{
	int conta;
	char nome[50];
	float saldo;
}Cliente;

typedef struct lista Lista;
Lista* cria_lista();
int busca_conta(Lista* li, int chave);
void insere_conta(Lista* li, Cliente novo);
void remove_conta(Lista* li, int chave);
int tamanho_lista(Lista* li);
void esvazia_lista(Lista* li);
void imprime_lista(Lista* li);

#endif // LISTACONTA_H_INCLUDED
