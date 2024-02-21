#include <stdio.h>
int main() {
	int n, i=1, k=1;
	scanf("%d", &n);
	printf("\n");
	while(i<=n){
		k=k*i;
		i++;
	}
	printf("%d \n", k);
	return 0;
}
