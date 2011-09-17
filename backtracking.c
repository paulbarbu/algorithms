#include <stdio.h>

int sol[100];

void display(int k){
    for(int i=0; i<=k; i++){
        printf("%d ", sol[i]);
    }

    printf("\n");
}

int solution(int k, int n){
    if(k == n-1){
        return 1;
    }

    return 0;
}

int valid(int k){
    for(int i=0; i<k;i++){
        if(sol[i] == sol[k]){
            return 0;
        }
    }

    return 1;
}

void bt(int k, int n){
    for(int i=1; i<=n; i++){ //change the range
        sol[k] = i;

        if(valid(k)){ //change the valid() function
            if(solution(k, n)){ //change the solution() function
                display(k); //change the display() function
            }
            else{
                bt(k+1, n);
            }
        }
    }
}

int main(){
    int n;
    printf("n= ");
    scanf("%d", &n);

    bt(0, n);

    return 0;
}
