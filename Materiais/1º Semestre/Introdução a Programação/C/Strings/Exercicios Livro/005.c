#include <stdio.h>
#include <locale.h>
#include <string.h>
int main(){
    char frase[100], frase_invertida[100];
    gets(frase);
    int i, tamanho_frase;
    tamanho_frase=strlen(frase);
    for(i=0; i<=tamanho_frase-1; i++){
        frase_invertida[i]=frase[tamanho_frase-1-i];
    }
    frase_invertida[tamanho_frase]='\0';
    printf("%s", frase_invertida);
    return 0;
}
