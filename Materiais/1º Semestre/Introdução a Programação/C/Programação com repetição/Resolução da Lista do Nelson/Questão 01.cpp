#include <stdio.h>
#include <locale.h>
int main() {
   	 setlocale(LC_ALL, "portuguese");
   	 int x, i;
    	printf("Digite um n�mero: \n");
    	scanf("%d", &x);
    	printf("Os divisores de %d s�o: \n", x);
    	for(i = 1; i<=x; i++){
        		if(x%i == 0){
            		printf("%d \n", i);
        		}
    	}
    	return 0;
}
