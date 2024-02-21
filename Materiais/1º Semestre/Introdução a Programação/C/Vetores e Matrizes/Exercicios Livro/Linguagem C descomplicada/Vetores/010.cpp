#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	int i, v[100];
	for(i=0; i<100; i++){
		v[i]=7+7*i;
	}
	for(i=0; i<100; i++){
		if(i==0){
			printf("(%d,", v[i]);
		}else if(i==99){
			printf("%d)", v[i]);
		}else{
			printf("%d,", v[i]);
		}
	}
	return 0;
}
