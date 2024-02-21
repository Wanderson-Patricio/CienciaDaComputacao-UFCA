#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	printf("\n\n");
	int v[n];
	for(int i=0; i<n; i++){
		v[i]=3*i;
		printf("%d \n", v[i]);
	}
	return 0;
}
