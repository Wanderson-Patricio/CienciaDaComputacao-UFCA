#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i; 
	float nota[5], nota_maior =0;
	char nome[5], pessoa;
	for(i=0; i<5; i++){
		printf("Qual o nome do aluno %d? \n", i+1);
		scanf("%s", &nome[i]);
		printf("Qual foi sua nota? \n");
		scanf("%f", &nota[i]);
		if(nota[i]>nota_maior){
			nota_maior=nota[i];
			pessoa=nome[i];
		}
	}
	printf("A pessoa com a maior nota foi %s. Ela tirou %.2f. \n", 'pessoa', nota_maior);
	return 0;
}
