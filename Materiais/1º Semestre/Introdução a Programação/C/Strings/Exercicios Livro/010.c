#include <stdio.h>
#include <locale.h>
int main(){
    char frase[100];
    gets(frase);
    int tamanho_frase=strlen(frase);
    for(int i=0; i<tamanho_frase; i++){
        if((frase[i]>=97)&&(frase[i]<=122)){
            frase[i]=frase[i]-32;
        }
    }
    printf("%s", frase);
    return 0;
}
