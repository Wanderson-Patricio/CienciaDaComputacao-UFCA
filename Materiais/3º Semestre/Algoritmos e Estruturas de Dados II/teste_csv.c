#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    char *S[1000], *ptr;
    FILE *fptr;

    // Abertura do arquivo de recursos
    fptr = fopen("recursos copy.csv", "r");

    while(fgets(S, 1000, fptr) != NULL){

        ptr = strtok(S, ",");

        while(ptr != NULL){
            printf("%s ", ptr);
            ptr = strtok(NULL, ",");
        }
    }

    fclose(fptr);


    return 0;
}

