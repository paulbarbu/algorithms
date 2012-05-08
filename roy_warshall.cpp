#include <iostream>
#include <fstream>

using namespace std;

int a[100][100], n, m, p[100][100];

ifstream f("rw.in");

void citire(){
	int x, y;
	
	for(int i=0; i<m; i++){
		f>>x>>y;
		a[x][y] = a[y][x] = 1;
		p[x][y] = p[y][x] = x;
	}
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

void rw_recon_drum(){
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			if(i != k){
				for(int j=1; j<=n; j++){
					if(j != k && a[i][j] == 0 && j != i){
						a[i][j] = a[i][k] * a[k][j];
						p[i][j] = k;
					}
				}
			}
		}
	}
}

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

void tip(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout<<a[i][j]<<' ';
		}
		
		cout<<"\n";
	}
}

void tip_p(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout<<p[i][j]<<' ';
		}
		
		cout<<"\n";
	}
}

void tip_lant(int x, int y){
	if(p[y][x] != 0){
		tip_lant(x, p[y][x]);
		cout<<y<<' ';
	}
	else{
		cout<<x<<' ';
	}
}

void ciclii(){
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			if(i != k){
				for(int j=1; j<=n; j++){
					if(j != k && a[i][j] == 0){
						a[i][j] = a[i][k] * a[k][j];
					}
				}
			}
		}
	}
}

int main(){
	f>>n>>m;
	citire();
	//tip();
	//rw();
	//rw_recon_drum();
	
	ciclii();
	
	cout<<"\n";
	tip();
	//tip_p();
	cout<<"\n";
	//tip_lant(1, 4);
	
	
	//cout<<"\nconex: "<<conex();
}