#include <iostream>

using namespace std;

int x[100] = {5, 2, 8, 6, 4, 9, 3, 12}, n=8, l[100], ant[100], m = -1, poz = -1;

void subsir(){
    l[0] = 1;
    ant[0] = -1;

    for(int i=1; i<n; i++){
        l[i] = 0;
        ant[i] = -1;

        for(int j=i-1; j>=0; j--){
            if(x[i] > x[j]){
                if(l[j] >= l[i]){
                    l[i] = l[j];
                    ant[i] = j;
                }
            }
        }

        l[i]++;

        if(l[i] > m){
            m = l[i];
            poz = i;
        }
    }
}

int main(){

    subsir();

    for(int i=0; i<n; i++){
        cout<<l[i]<<" ";
    }

    cout<<"\n\n";

    while(poz != -1){
        cout<<x[poz]<<" ";
        poz = ant[poz];
    }

}
