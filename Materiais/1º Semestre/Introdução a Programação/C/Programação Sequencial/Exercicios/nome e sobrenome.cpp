#include <stdio.h>
int main(){
      char nome[100];
      char sobrenome[100];
      printf("Digite seu nome\n");
      scanf("%s", &nome);
      printf("Digite seu sobrenome\n");
      scanf("%s", &sobrenome);
      printf("Seu nome é: %s %s\n", nome, sobrenome);
      return 0;
}
