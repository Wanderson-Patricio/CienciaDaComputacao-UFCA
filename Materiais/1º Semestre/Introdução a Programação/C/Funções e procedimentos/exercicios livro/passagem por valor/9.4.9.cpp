#include <stdio.h>
#include <locale.h>
float media(float nota_1, float nota_2, float nota_3, char s){
	float media=0;
	if((s=='A')||(s=='a')){
		media=(nota_1+nota_2+nota_3)/3;
	}else if((s=='P')||(s=='p')){
		media=(5*nota_1+3*nota_2+2*nota_1)/10;
	}
	return media;
}
int main(){
	printf("%.3f\n", media(10, 5, 5, 'a'));
	printf("%.3f\n", media(10, 5, 5, 'p'));
	return 0;
}
