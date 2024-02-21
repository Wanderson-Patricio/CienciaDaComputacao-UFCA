#include <stdio.h>
#include <locale.h>
int main(){
    char frase[100];
    gets(frase);
    int i, tamanho_frase=strlen(frase);
    for(i=tamanho_frase-1; i>=0; i--){
        printf("%c", frase[i]);
    }
    return 0;
}
