#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, n;
	float H=0;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		H = H + (float) 1/i;
	}
	printf("O %d� n�mero harm�nico � %f.", n, H);
	return 0;
}
