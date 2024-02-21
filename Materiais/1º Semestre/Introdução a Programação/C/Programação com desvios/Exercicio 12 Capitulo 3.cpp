#include <stdio.h>
#include <math.h>
int main() {
	float r, h, v;
	scanf("%f %f", &r, &h);
	v=(M_PI)*r*r*h;
	printf("%.3f \n", v);
	return 0;
}
