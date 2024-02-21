#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, A[6]={1,0,5,-2,-5,7}, soma;
	soma=A[0]+A[1]+A[5];
	printf("A[0]+A[1]+A[5]=%d \n", soma);
	A[4]=100;
	for(i=0; i<6; i++){
		printf("%d \n", A[i]);
	}
	return 0;
}
