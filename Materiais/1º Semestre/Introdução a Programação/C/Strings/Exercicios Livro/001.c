#include <stdio.h>
#include <locale.h>
#include <string.h>
int main(){
    char frase[100];
    printf("Digite uma frase: \n");
    gets(frase);
    printf(frase);
    return 0;
}
