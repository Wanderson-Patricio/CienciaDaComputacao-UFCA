#include <stdio.h>
#include <locale.h>
#include <math.h>

int isPrime(int n){
    int divisors = 0;

    for(int i=1; i<=n; i++){
        if(n%i == 0){
            divisors++;
        }
    }

    return (divisors == 2)? 1 : 0;
}

int main(){
    setlocale(LC_ALL, "portuguese");
    int counting = 0;
    int n = 1000;

    for(int m=1; m<=pow(2,n); m++){
        if(isPrime(m) == 1){
            counting++;
            printf("%dº primo : %d \n", counting, m);
        }

        if(counting == n){
            break;
        }
    }

    return 0;
}
