#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
	float A, B, C;
	printf("Quais são os valores dos lados do triângulo? \n");
	scanf("%f %f %f", &A, &B, &C);
	if(A < 0 || B < 0 || C < 0){
		printf("O triângulo não existe. \n");
		return 0;
	}else if(A == B && A == C){
		printf("O triângulo existe e é equilatéro. \n");
	}else if(A == B && A > C && A < B + C){
		printf("O triângulo existe e é isósceles; \n");
	}else if(A > B && A == C && A < B + C){
		printf("O triângulo existe e é isósceles; \n");	
	}else if(A > B && A > C && A < B + C){
		printf("O triângulo existe e é escaleno. \n");
	}else if(A >= B + C){
		printf("O triângulo não existe. \n");
	}else if(B == A && B == C){
		printf("O triângulo existe e é equilatéro. \n");
	}else if(B == A && B > C && B < A + C){
		printf("O triângulo existe e é isósceles; \n");
	}else if(B > A && B == C && B < A + C){
		printf("O triângulo existe e é isósceles; \n");	
	}else if(B > A && B > C && B < A + C){
		printf("O triângulo existe e é escaleno. \n");
	}else if(B >= A + C){
		printf("O triângulo não existe. \n");
	}else if(C == B && C == A){
		printf("O triângulo existe e é equilatéro. \n");
	}else if(C == B && C > A && C < B + A){
		printf("O triângulo existe e é isósceles; \n");
	}else if(C > B && C == A && C < B + A){
		printf("O triângulo existe e é isósceles; \n");	
	}else if(C > B && C > A && C < B + A){
		printf("O triângulo existe e é escaleno. \n");
	}else if(C >= B + A){
		printf("O triângulo não existe. \n");
	}
	return 0;
}
