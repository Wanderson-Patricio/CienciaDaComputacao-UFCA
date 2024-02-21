#include <stdio.h>
int main() {
	int i, a=-1, b=0;
	float S=0;
	for(i=1; i<=50; i++){
		a=a+2;
		b=b+1;
		S=S+(float) a/b;
	}
	printf("%f", S);
	return 0;
}
