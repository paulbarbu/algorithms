/**
 * compute the minimum and the maximum in a vector using divide-et-impera
 */
#include <iostream>

using namespace std;

int a[100], n, minim=1000, maxim=-1000;

int minmax(int s, int d){
    if(s==d){
        if(a[s]>=maxim){
            maxim = a[s];
            return maxim;
        }
        else{
            if(a[s]<=minim){
                minim = a[s];
                return minim;
            }
        }
    }
    else{
        int mjl = (s+d)/2;
        int r1 = minmax(s, mjl);
        int r2 = minmax(mjl+1, d);

        if(r1>=maxim){
            maxim = r1;
        }
        else if(r2>=maxim){
            maxim = r2;
        }

        if(r1<=minim){
            minim = r1;
        }
        else if(r2<=minim){
            minim = r2;
        }
    }
}

int main()
{
    n=3;
    a = {-3, -1, -20, -2};
    minmax(0, n);
    cout<<minim<<' '<<maxim;
    return 0;
}
