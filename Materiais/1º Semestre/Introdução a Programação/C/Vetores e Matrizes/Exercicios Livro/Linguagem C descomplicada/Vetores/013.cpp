#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, j, v[10];
	for(i=0; i<10; i++){
		printf("Digite um número: ");
		scanf("%d", &v[i]);
		for(j=0; j<i; j++){
			if(v[j]==v[i]){
				printf("Esse número já foi digitado. Digite outro número: ");
				scanf("%d", &v[i]);
			}
		}
	}
	for(i=-1; i<10; i++){
		if(i==-1){
			printf("\n V=");
		}else if(i==0){
			printf("(%d,", v[i]);
		}else if(i==9){
			printf("%d) \n", v[i]);
		}else{
			printf("%d,", v[i]);
		}
	}
	return 0;
}
