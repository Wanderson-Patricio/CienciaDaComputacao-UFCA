#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

int verifica_menor(char a[], char  b[]){
	if(strlen(a)<strlen(b)){
		return 0;
	}else{
		return 1;
	}
}

int main(){
	setlocale(LC_ALL, "portuguese");
	char frase1[100] = "O rato roeu a roupa do rei de Roma.", frase2[100] = "O rato roeu";
	char *pont1 = frase1, *pont2 = frase2;
	int contador = 0, verificador = 0, i, j;
	int k = verifica_menor(frase1, frase2);
	switch(k){
		case 0: printf("A segunda frase é maior.\n"); break;
		case 1: {
			for(i=0; frase1[i]!='\0'; i++){
				if(frase1[i]==frase2[0]){
					for(j=0; frase2[j]!='\0'; j++){
						if(*(pont1+i+j)==*(pont2+j)){
							contador++;
						}
					}
					if(contador==strlen(frase2)){
						verificador = 1;
					}
					contador = 0;
				}
			}
			if(verificador == 0){
				printf("A segunda não frase está contida na primeira.\n");
			}else{
				printf("A segunda frase está contida na primeira.\n");
			}
			break;
		}
	}
	return 0;
}
