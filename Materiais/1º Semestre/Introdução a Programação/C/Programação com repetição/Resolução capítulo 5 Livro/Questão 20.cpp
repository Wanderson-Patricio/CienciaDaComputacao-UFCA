#include <stdio.h>
int main() {
	int j=1, i, n, k=1;
	float E=0;
	scanf("%d", &n);
	while(j<=n){
		for(i=1; i<=j; i++){
			k=k*i;
		}
		E=E+(float)1/k;
		k=1;
		j++;
	}
	printf("%f", E);
	return 0;
}
