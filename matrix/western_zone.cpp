/**
 * In a bidimensional array get the elements in the west
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
    for(i=1;i<=(n-1)/2;i++){
        for(j=0;j<i;j++){
            printf("%d ", a[i][j]);
        }
    }
    for(i=(n-1)/2+1;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            printf("%d ", a[i][j]);
        }
    }

    printf("\n\n");

    for(j=0;j<(n-1)/2;j++){
        for(i=j+1;i<n-1-j;i++){
            printf("%d ", a[i][j]);
        }
    }

    printf("\n\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i>j && i+j<n-1){
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
