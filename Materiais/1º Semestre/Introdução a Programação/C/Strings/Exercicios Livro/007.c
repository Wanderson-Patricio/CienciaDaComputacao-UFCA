#include <stdio.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL, "portuguese");
    char frase[100];
    gets(frase);
    int i, tamanho_frase=strlen(frase), palindromo=0;
    for(i=0; frase[i]!='\0'; i++){
        if(frase[i]==frase[tamanho_frase-1-i]){
            palindromo++;
        }
    }
    if(palindromo==tamanho_frase){
        printf("A palavra é palindroma.");
    }else{
        printf("A palavra não é palíndroma.");
    }
    return 0;
}
