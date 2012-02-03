/**
 * Compute the factorial of a number using divide-et-impera
 */
#include <iostream>

using namespace std;

int n_fact(int s, int d){
    if(s==d){
        if(s!=0){
            return s;
        }
        else{
            return 1;
        }
    }
    else{
        int mjl = (s+d)/2;
        int r1 = n_fact(s, mjl);
        int r2 = n_fact(mjl+1, d);

        return r1*r2;
    }
}

int main()
{
    cout << n_fact(0, 3);
    return 0;
}
