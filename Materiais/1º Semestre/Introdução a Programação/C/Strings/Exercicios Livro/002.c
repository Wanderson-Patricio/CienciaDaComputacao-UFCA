#include <stdio.h>
#include <locale.h>
#include <string.h>
int main(){
    int i;
    char palavra[50];
    printf("Digite uma palavra:\n");
    gets(palavra);
    for(i=0; i<4; i++){
        printf("%c", palavra[i]);
    }
    return 0;
}
