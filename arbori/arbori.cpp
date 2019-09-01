#include <iostream>
#include <fstream>

using namespace std;

int n, m, A[100][100], T[100], root;
bool viz[100];

void resetT(){
	for(int i=1; i<=n; i++){
		T[i]=0;
	}
}

void resetA(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			A[i][j] = 0;
		}
	}
}

void AtoT(int r){
	viz[r] = true;
	for(int i=1; i<=n; i++){
		if(!viz[i] && A[r][i]){
			viz[i] = true;
			T[i] = r;
			AtoT(i);
		}
	}
}

void TtoA(){
	for(int i=1; i<=n; i++){
		A[i][T[i]] = A[T[i]][i] = 1;
	}
}

int main(){
	ifstream f("arbori.in");
	f>>n>>root;
	m=n-1;
	resetT();

	for(int i=0; i<m; i++){
		int x, y;
		f>>x>>y;
		A[x][y]=A[y][x]=1;
	}

	cout<<"A:\n";
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}

	AtoT(root);

	cout<<"\nT: ";
	for(int i=1; i<=n; i++){
		cout<<T[i]<<" ";
	}

	resetA();

	TtoA();

	cout<<"\nA:\n";
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}
}