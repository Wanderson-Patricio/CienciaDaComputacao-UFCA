#include <stdio.h>
int main() {
	int j=1, i, n, k=1;
	scanf("%d", &n);
	printf("\n");
	while(j<=n){
		for(i=1; i<=j; i++){
			printf("%d ", k);
			k++;
		}
		printf("\n");
		j++;
	}
	return 0;
}
