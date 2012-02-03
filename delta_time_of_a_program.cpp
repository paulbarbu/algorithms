#include <time.h> //important!
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    double start=clock(), cps=CLOCKS_PER_SEC;

    // {{{ intensive calculations here
    int ct=0;

    for(int i=0; i<=1000000000; i++){
        ct++;
    }
    // }}}

    printf("Delta time: %.3lf\n",(clock()-start)/cps);


    cout.precision(3);
    cout<<"Delta time:"<<(clock()-start)/cps;
    return 0;
}

