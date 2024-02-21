#include <stdio.h>
#include <locale.h>
#include <string.h>
int main(){
    setlocale(LC_ALL, "portuguese");
    char mercadoria[5][100];
    float preco[5];
    int i;
    for(i=0; i<5; i++){
        printf("Qual o nome da %dª mercadoria? \n", i+1);
        gets(mercadoria[i][100]);
        printf("Qual o preço dela? \n");
        scanf("%f", &preco[i]);
    }
    for(i=0; i<5; i++){
        printf("%s >>> Preço total: R$%.2f , desconto: R$%.2f, valor a pagar a vista: R$%.2f \n", mercadoria[i], preco[i], 0.1*preco[i], 0.1*preco[i]);
    }
    return 0;
}
