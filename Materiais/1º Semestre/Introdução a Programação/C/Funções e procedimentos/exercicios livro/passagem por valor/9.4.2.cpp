#include <stdio.h>
#include <locale.h>
void mes(int data){
	switch(data){
		case 1: printf("Janeiro: 31 dias.\n"); break;
		case 2: printf("Fevereiro: 28 dias.\n"); break;
		case 3: printf("Março: 31 dias.\n"); break;
		case 4: printf("Abril: 30 dias.\n"); break;
		case 5: printf("Maio: 31 dias.\n"); break;
		case 6: printf("Junho: 30 dias.\n"); break;
		case 7: printf("Julho: 31 dias.\n"); break;
		case 8: printf("Agosto: 31 dias.\n"); break;
		case 9: printf("Setembro: 30 dias.\n"); break;
		case 10: printf("Outubro: 31 dias.\n"); break;
		case 11: printf("Novembro: 30 dias.\n"); break;
		case 12: printf("Dezembro: 31 dias.\n"); break;
	}
}
int main(){
	setlocale(LC_ALL, "portuguese");
    int data=0;
    while((data<1)||(data>12)){
    	printf("Digite um número: ");
    	scanf("%d", &data);
	}
	mes(data);
    return 0;
}
