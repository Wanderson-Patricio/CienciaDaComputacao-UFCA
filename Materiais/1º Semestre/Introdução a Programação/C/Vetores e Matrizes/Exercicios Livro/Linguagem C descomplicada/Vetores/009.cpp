#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, a[10], b[10], c[10];
	for(i=0; i<10; i++){
		printf("Digite a[%d]: ", i);
		scanf("%d", &a[i]);
	}
	printf("\n");
	for(i=0; i<10; i++){
		printf("Digite b[%d]: ", i);
		scanf("%d", &b[i]);
	}
	printf("\n");
	for(i=0; i<10; i++){
		c[i]=a[i]-b[i];
	}
	printf("\n");
	for(i=0; i<10; i++){
		if(i==0){
			printf("A-B=(%d,", c[i]);
		}else if(i==9){
			printf("%d)", c[i]);
		}else{
			printf("%d,", c[i]);
		}
	}
	return 0;
}
