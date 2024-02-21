#include <stdio.h>
#include <locale.h>
float maior(float a, float b){
    float z;
    if(a>b){
        z=a;
    }else{
        z=b;
    }
    return z;
}
int main(){
	setlocale(LC_ALL, "portuguese");
    float a,b;
    printf("Digite dois números: \n");
    scanf("%f %f", &a, &b);
    printf("%.2f é o maior deles.", maior(a,b));
    return 0;
}
