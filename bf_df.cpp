#include <iostream>
#include <fstream>

using namespace std;

int c[100], viz[100], n, a[100][100];

void bf(int x){
    c[0] = x;
    viz[x] = 1;
    int p = 0;
    int u = 0;

    while(p<=u){
        int k = c[p];

        for(int i=1; i<=n; i++){
            if(1 == a[k][i] && 0 == viz[i]){
                u++;
                c[u] = i;
                viz[i] = 1;
            }
        }

        p++;
    }
}

void bf_tip(){
    int i=0;

    while(c[i]){
        cout<<c[i++]<<' ';
    }
}

void init(){
    for(int i=0; i<=n; i++){
        c[i] = 0;
        viz[i] = 0;
    }
}

void df(int x){
    viz[x] = 1;
    cout<<x<<' ';

    for(int i=1; i<=n; i++){
        if(a[x][i] && !viz[i]){
            df(i);
        }
    }
}

int main(){
    int m, x, y;
    ifstream f("bf_df.in");

    f>>n>>m;
    for(int i=0; i<=m; i++){
        f>>x>>y;
        a[x][y] = a[y][x] = 1;
    }

    cout<<"BF:\n";

    for(int i=1; i<=n; i++){
        bf(i);
        bf_tip();
        init();
        cout<<"\n";
    }

    cout<<"DF:\n";

    for(int i=1; i<=n; i++){
        df(i);
        init();
        cout<<"\n";
    }

    f.close();
}

