#include <stdio.h>
#include <locale.h>
#include <string.h>
int main(){
    int tamanho=0, i;
    char frase[100];
    gets(frase);
    for(i=0; frase[i]!='\0'; i++){
        if(frase[i]!=' '){
            tamanho++;
        }
    }
    printf("%d", tamanho);
    return 0;
}
