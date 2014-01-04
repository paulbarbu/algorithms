#include <iostream>

using namespace std;

int a[100], n;

int cautp(int s, int d){
    int i=s, j=d, x=a[s];

    while(i<j){
        while(a[j]>x && i<j){
            j--;
        }
        a[i] = a[j];

        while(a[i]<x && i<j){
            i++;
        }
        a[j]=a[i];
    }
    a[i] = x;
    return i;
}

void quicksort(int s, int d){
    int p = cautp(s, d);

    if(s<p-1){
        quicksort(s, p-1);
    }

    if(d>p+1){
        quicksort(p+1, d);
    }
}

int main()
{
    a = {2, 1, 7, 3, 5, 6};
    n=6;
    quicksort(0, n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}
