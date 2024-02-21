#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int x;
	scanf("%d", &x);
	if(x < 0){
		printf("%d", x*x);
	}else{
		printf("%.4f", (float) sqrt(x));
	}
	return 0;
}
