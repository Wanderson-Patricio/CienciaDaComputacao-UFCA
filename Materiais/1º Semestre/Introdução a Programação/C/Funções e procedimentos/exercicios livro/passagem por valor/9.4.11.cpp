#include <stdio.h>
int pot(int x, int y){
	int res=1;
	for(int i=1;i<=y; i++){
		res*=x;
	}
	return res;
}
int main(){
	printf("%d", pot(5,4));
	return 0;
}
