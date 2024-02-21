#include <stdio.h>
#include <locale.h>
float volume(float r){
	float vol=(4.0/3)*3.141592*r*r*r;
	return vol;
}
int main(){
	setlocale(LC_ALL, "portuguese");
    printf("%.4f", volume(10));
    return 0;
}
