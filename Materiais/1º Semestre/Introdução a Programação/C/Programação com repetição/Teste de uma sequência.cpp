#include <stdio.h>
int main(){
	int a=3, b=-1, c, i, n;
	scanf("%d", &n);
	printf("\n");
	for(i=1; i<=n; i++){
		c=a+2*b;
		a=b;
		b=c;
		printf("%d \n", c);
	}
	return 0;
}
