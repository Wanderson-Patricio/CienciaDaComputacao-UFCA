#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i;
	float x, f, der;
	scanf("%f", &x);
	f=pow(x,3)-4*x+2;
	der=3*pow(x,2)-4;
	for(i=1; i<=10; i++){
		x=x-f/(der);
		f=pow(x,3)-4*x+2;
		der=3*pow(x,2)-4;
	}
	printf("\n %f", x);
	return 0;
}
