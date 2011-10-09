/**
 * Moving a knight all over the chess board using plain backtracking
 */
#include <iostream>

using namespace std;

int a[100][100], n = 5, sol[1000][2], mi[] = {-1, 1, 2, 2, 1, -1, -2, -2},
    mj[] = {2, 2, 1, -1, -2, -2, -1, 1}, k = 0;

void tip(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}

void back(int i, int j){
    if(i < n && i > -1 &&
       j < n && j > -1 &&
       a[i][j] == 0){

        k++;
        a[i][j] = k;

        if(k == n*n){
            tip();
        }
        else{
            for(int x=0; x<8; x++){
                back(i + mi[x], j + mj[x]);
            }
        }

        k--;
        a[i][j] = 0;

    }
}

int main(){

    back(0, 0);

    return 0;
}
