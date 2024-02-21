#include <stdio.h>
void horario(int h, int min, int s){
	printf("%dh%dmin%ds", h, min, s);
}
int main(){
	int h, min, s;
	scanf("%d %d %d", &h, &min, &s);
	horario(h, min, s);
	return 0;
}
