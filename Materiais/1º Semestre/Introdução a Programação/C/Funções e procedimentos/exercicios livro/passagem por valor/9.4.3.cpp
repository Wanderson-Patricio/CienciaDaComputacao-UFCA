#include <stdio.h>
#include <locale.h>
float celsius(float f){
	float temp=(5*f-160)/9;
	return temp;
}
int main(){
	setlocale(LC_ALL, "portuguese");
    printf("%.2f", celsius(212));
    return 0;
}
