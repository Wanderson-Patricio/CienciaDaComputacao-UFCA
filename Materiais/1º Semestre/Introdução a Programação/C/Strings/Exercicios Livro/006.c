#include <stdio.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL, "portuguese");
    char frase[100];
    gets(frase);
    int i, tamanho_frase=strlen(frase), vogais=0;
    char vogal;
    printf("Escolha uma letra para substituir as vogais: ");
    scanf("%c", &vogal);
    for(i=0; i<frase[i]!='\0'; i++){
        if((frase[i]=='a')||(frase[i]=='e')||(frase[i]=='i')||(frase[i]=='o')||(frase[i]=='u')){
            vogais++;
            frase[i]=vogal;
        }
    }
    printf("A frase possui %d vogais. \n", vogais);
    printf("Frase substituída: %s", frase);
    return 0;
}
