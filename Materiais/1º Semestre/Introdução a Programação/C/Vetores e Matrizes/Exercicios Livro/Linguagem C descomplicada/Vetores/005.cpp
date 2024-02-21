#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, a[8], x, y;
	for(i=0; i<8; i++){
		printf("Digite a[%d]:", i);
		scanf("%d", &a[i]);
	}
	printf("Escoha duas posições: \n");
	scanf("%d %d", &x, &y);
	while((x<0)||(x>7)||(y<0)||(y>8)){
		printf("Inválido, digite novamente: \n");
		scanf("%d %d", &x, &y);
	}
	printf("a[%d]+a[%d]=%d", x, y, a[x]+a[y]);
	return 0;
}
