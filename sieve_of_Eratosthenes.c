/**
 * Using the Sieve of Eratosthenes display all prime numbers smaller(or equal) than "n"
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;

    scanf("%d", &n);

    int *sieve = malloc(sizeof(int) * n+1);

    for(int i=2; i<=n; i++){
        for(int j=i+i; j<=n; j=j+i){
            sieve[j] = -1;
        }
    }

    for(int i=2; i<=n; i++){
        printf("%d ", sieve[i]);
    }

    printf("\n");

    free(sieve);

    return 0;
}
