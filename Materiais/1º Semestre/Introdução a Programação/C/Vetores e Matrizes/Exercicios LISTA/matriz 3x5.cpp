#include <stdio.h>
int main() {
	int mat[3][5], i, j;
	for(i=0; i<3; i++){
		for(j=0; j<5; j++){
			printf("Digite mat[%d][%d]:", i,j);
			scanf("%d", &mat[i][j]);
		}
	}
	for(i=0; i<3; i++){
		for(j=0; j<5; j++){
			if(j==4){
				printf("%d", mat[i][j]);
			}else{
				printf("%d,", mat[i][j]);
			}
		}
		printf("\n");
	}
}
