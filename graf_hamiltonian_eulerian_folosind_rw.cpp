#include <iostream>
#include <fstream>

using namespace std;

int st[100], a[100][100], n, m, uz[100], hamiltonian = 0;


// GRAF HAMILTONIAN
int valid(int k){
    if(k == 1){
        return 1;
    }

    if(a[st[k]][st[k-1]]){
        return 1; //exista muchie intre nodul curent si cel precedent
    }

    return 0;
}

void tip(int k){
    for(int i=1; i<=k; i++){
        cout<<st[i]<<' ';
    }

    cout<<"\n";
}

int sol(int k){
    if(k == n && a[st[k]][st[1]]){
        return 1;
    }

    return 0;
}

void ch(int k){
    for(int i=1; i<=n; i++){
        st[k] = i;

        if(!uz[i] && valid(k)){
            uz[i] = 1;

            if(sol(k)){
                hamiltonian = 1;
                //tip(k);
                return;
            }
            else{
                ch(k+1);
            }

            uz[i] = 0;
        }
    }
}

//GRAF EULERIAN
int grad(int x){
    int s=0;

    for(int i=1; i<=n; i++){
        if(a[x][i]){
            s++;
        }
    }

    return s;
}

int grade_pare(){
    for(int i=1; i<=n; i++){
        if(grad(i) % 2 != 0){
            return 0;
        }
    }

    return 1;
}

//GRAF CONEX
int conex(){
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if(a[i][j] == 0){
                return 0;
            }
        }
    }

    return 1;
}

void rw(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            if(i != k){
                for(int j=1; j<=n; j++){
                    if(j != k && a[i][j] == 0 && j != i){
                        a[i][j] = a[i][k] * a[k][j];
                    }
                }
            }
        }
    }
}

int main(){
    int z, v;
    ifstream f("ghe.in");

    f>>n>>m;

    for(int i=0; i<m; i++){
        f>>z>>v;
        a[z][v] = a[v][z] = 1;
    }

    ch(1);

    int gr_pare = grade_pare();
    rw();

    cout<<"Hamiltonian: "<<hamiltonian;
    int eulerian = conex() & gr_pare;
    cout<<"\nEulerian: "<<eulerian;


    f.close();
}
