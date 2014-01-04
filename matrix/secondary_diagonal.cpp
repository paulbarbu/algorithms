/**
 * In a bidimensional array get the elements on the secondary diagonal
 */
#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main()
{
    int n, m, i, j;

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
            printf("%d ", a[i][n-1-i]);
    }
    printf("\n\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i+j==n-1){
                printf("%d ", a[i][j]);
            }
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
