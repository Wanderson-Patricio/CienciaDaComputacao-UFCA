#include <stdio.h>

int fib(int n){
    int s0 = n;
    if(s0 == 0){
        return(base_case(s0));
    }
    int t0 = 1;
    if(s0 == t0){
        return base_case(s0);
    }

    int a0 = s0-1;
    int s1 = fib(a0);
    a0 = a0-1;
    int v0 = fib(a0);
    v0 = v0+s1;
    return v0;
}

int base_case(int n){
    return n;
}

int main(){
    print("%d \n", fin(5));
    return 0;
}
