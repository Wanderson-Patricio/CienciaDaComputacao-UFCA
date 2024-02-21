#include <stdio.h>
int main() {
	int i, soma=0;
	for(i=1; i<=10000; i++){
		soma+=i;
	}
	printf("%d", soma);
	return 0;
}
