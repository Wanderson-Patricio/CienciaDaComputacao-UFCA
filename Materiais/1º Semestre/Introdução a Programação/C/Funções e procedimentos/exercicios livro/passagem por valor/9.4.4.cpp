#include <stdio.h>
#include <locale.h>
float volume(float r, float h){
	return 3.141592*r*r*h;
}
int main(){
	setlocale(LC_ALL, "portuguese");
    printf("%.3f", volume(2,4));
    return 0;
}
