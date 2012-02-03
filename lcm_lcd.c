/**
 * Compute the Lowest common denominator(cmmdc) and Least common multiple(cmmmc)
 */
#include <stdio.h>

int cmmdc_euclid(int a, int b){
    int r;
    while(a%b!=0){
        r=a% b;
        a=b;
        b=r;
    }

    return b;
}

int cmmdc(int a, int b){
    while(a!=b){
        if(a>b){
            a-=b;
        }
        else{
            b-=a;
        }
    }

    return b;
}

int cmmmc(int a, int b){
    return a*b/cmmdc(a,b);
}

int main(){
    printf("%d, %d, %d\n", cmmdc(42, 12), cmmdc(42 ,13), cmmmc(2, 3));
}
