#include <stdio.h>
#include <stdlib.h>

void out(int *a, int n){
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }

    printf("\n");
}

int check(int *a, int k, int n){
    for(int i=k+1; i<n; i++){
        if(a[k] > a[i]){
            return 0;
        }
    }

    return 1;
}

int max_poz(int *L, int n){
    int max = 0, poz = -1;

    for(int i=0; i<n; i++){
        if(L[i] >= max){
            max = L[i];
            poz = i;
        }
    }

    return poz;
}

void max_l(int *a, int *L, int n){
    L[n-1] = 1;

    for(int k=n-2; k>=0; k--){
        if(check(a, k, n)){
            L[k] = 1 + L[max_poz(L, n)];
        }
        else{
            L[k] = 1;
        }
    }
}

void drum(int *a, int *L, int n){
    int poz = max_poz(L, n), m = L[poz];

    printf("Sirul strict crescator este: %d ", a[poz]);
    m--;

    for(int i=poz+1; i<n; i++){
        if(L[i] == m){
            printf("%d ", a[i]);
            m--;
        }
    }

    printf("\n");
}

int main(){
    FILE *f;

    int n;

    f = fopen("fis.in", "r");

    fscanf(f, "%d", &n);


    int *a = malloc(sizeof(int)*n), *L = malloc(sizeof(int)*n);

    for(int i=0; i<n; i++){
        fscanf(f, "%d", &a[i]);
        L[i] = 0;
    }

    fclose(f);

    out(a, n);

    max_l(a, L, n);

    out(L, n);

    drum(a, L, n);

    return 0;
}

