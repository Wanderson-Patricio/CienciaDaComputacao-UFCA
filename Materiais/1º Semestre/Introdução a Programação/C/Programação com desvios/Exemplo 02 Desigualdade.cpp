#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float A, B, C;
	printf("Quais s�o os valores dos lados do tri�ngulo? \n");
	scanf("%f %f %f", &A, &B, &C);
	if(A < 0 || B < 0 || C < 0){
		printf("O tri�ngulo n�o existe. \n");
		return 0;
	}else if(A == B && A == C){
		printf("O tri�ngulo existe e � equilat�ro. \n");
	}else if(A == B && A > C && A < B + C){
		printf("O tri�ngulo existe e � is�sceles; \n");
	}else if(A > B && A == C && A < B + C){
		printf("O tri�ngulo existe e � is�sceles; \n");	
	}else if(A > B && A > C && A < B + C){
		printf("O tri�ngulo existe e � escaleno. \n");
	}else if(A >= B + C){
		printf("O tri�ngulo n�o existe. \n");
	}else if(B == A && B == C){
		printf("O tri�ngulo existe e � equilat�ro. \n");
	}else if(B == A && B > C && B < A + C){
		printf("O tri�ngulo existe e � is�sceles; \n");
	}else if(B > A && B == C && B < A + C){
		printf("O tri�ngulo existe e � is�sceles; \n");	
	}else if(B > A && B > C && B < A + C){
		printf("O tri�ngulo existe e � escaleno. \n");
	}else if(B >= A + C){
		printf("O tri�ngulo n�o existe. \n");
	}else if(C == B && C == A){
		printf("O tri�ngulo existe e � equilat�ro. \n");
	}else if(C == B && C > A && C < B + A){
		printf("O tri�ngulo existe e � is�sceles; \n");
	}else if(C > B && C == A && C < B + A){
		printf("O tri�ngulo existe e � is�sceles; \n");	
	}else if(C > B && C > A && C < B + A){
		printf("O tri�ngulo existe e � escaleno. \n");
	}else if(C >= B + A){
		printf("O tri�ngulo n�o existe. \n");
	}
	return 0;
}
