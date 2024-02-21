#include <stdio.h>
#include <math.h>
#include "header.h"

#define PI M_PI

int factorial(int n){
    int result = 1;
    for(int i = 2; i<=n; i++){
        result*=i;
    }

    return result;
}

int Floor(float x){
    if(x>=0){
        return ((int) x/1);
    }

    for(int i = (int) 2*x; i<0; i++){
        if((i<=x) && (i+1>x)){
            return i;
        }
    }
}

int pot2(int n){
    int result = 1;

    if(n>0){
        for(int i = 1; i<=n; i++){
            result*=2;
        }
    }

    return result;
}

float nRoot(float x, int n){
    return pow(x, 1.0/n);
}

int isPrime(int n){
    int divisors = 1;

    for(int i=2; i<n; i++){
        if(n%i == 0){
            divisors = 0;
            break;
        }
    }

    return divisors;
}


void printPrimes(int n){
    for(int i=1; i<=n; i++){
        printf("%dº primo: %d \n", i, prime(i));
    }
}



int prime(int n){
    int soma = 1;
    int somaInt;
    for(int m = 1; m<=pot2(n); m++){
        somaInt = 0;
        for(int k=3; k<=n; k++){
            somaInt += ( factorial(k-1) - k*Floor( (float) (factorial(k-1) + 1)/k ) );
        }

        soma+= Floor(nRoot((float) n/somaInt,n));
    }

    return soma;
}
