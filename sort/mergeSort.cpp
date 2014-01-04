#include <iostream>

using namespace std;

int a[100], n;

void interclasare(int s, int d, int mjl){
    int i = s, j = mjl+1, k = 0, c[100];

    while(i<=mjl && j<=d){
        if(a[i]<=a[j]){
            c[k++] = a[i++];
        }
        else{
            c[k++] = a[j++];
        }
    }

    while(i<=mjl){
        c[k++] = a[i++];
    }

    while(j<=d){
        c[k++] = a[j++];
    }

    k=0;
    for(i=s;i<=d;i++){
        a[i] = c[k++];
    }
}

void mergesort(int s, int d){
    if(s<=d){
        int mjl = (s+d)/2;
        mergesort(s, mjl);
        mergesort(mjl+1, d);

        interclasare(s, d, mjl);
    }
}

int main()
{
    a = {2, 1, 7, 3, 5, 6};
    n = 6;

    mergesort(0, n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }

    return 0;
}
