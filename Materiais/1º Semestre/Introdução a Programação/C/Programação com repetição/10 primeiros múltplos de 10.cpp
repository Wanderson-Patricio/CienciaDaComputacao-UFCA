#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, j=0;
	for(i=1; i<=10; i++){
		printf("%d \n", 3*i);
	}
	return 0;
}
