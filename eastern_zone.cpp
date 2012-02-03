/**
 * In a bidimensional array get the elements in the east
 */
#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main()
{
    int n, m, i, j, pR, pC;

    ifstream in("intrare.in");
    ofstream out("iesire.out");

    in>>n>>m;

    int a[n][m];

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            in>>a[i][j];
        }
    }
    /////////////////////////////////

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i<j && i+j>n-1){
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n\n");

    for(j=(n-1)/2+1;j<n;j++){
        for(i=n-j;i<j;i++){
            printf("%d ", a[i][j]);
        }
    }
    printf("\n\n");

    /////////////////////////////////


    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    cin.get();

}
