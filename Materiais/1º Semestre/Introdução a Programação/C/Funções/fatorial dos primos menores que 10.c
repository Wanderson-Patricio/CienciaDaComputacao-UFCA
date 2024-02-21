#include <stdio.h>
int fatorial(int n){
    int fat=1;
    for(int i=1; i<=n; i++){
        fat*=i;
    }
    return fat;
}
int primo(int n){
    int p=0, divisores=0;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            divisores++;
        }
    }
    if(divisores==2){
        p=1;
    }
    return p;
}
int main(){
    int soma=0;
    for(int i=1; i<=10; i++){
        if(primo(i)==1){
            soma+=fatorial(i);
        }
    }
    printf("Soma= %d", soma);
    return 0;
}
