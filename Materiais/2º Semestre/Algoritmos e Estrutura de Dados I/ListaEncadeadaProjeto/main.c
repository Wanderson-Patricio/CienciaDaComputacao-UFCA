#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "cabecalho.h"

// **************AJEITAR OS CASOS DE 4 A 10*********************//


int main() {
    setlocale(LC_ALL, "portuguese");
    Lista *li = criarLista();

    inicializaListaCapitais(li);




    imprimeListaPopulacao(li);


    esvaziaLista(li);
    free(li);
    li = NULL;
    return 0;
}
