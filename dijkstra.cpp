#include <iostream>
#include <fstream>
#include <climits>

//#define INT_MAX 1000

using namespace std;

int m, n, a[100][100], x;

ifstream f("graf.txt");

void init_matrice(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			//if(i == j){
			//	a[i][i] = 0;
			//}
			//else{
				a[i][j] = INT_MAX;
			//}
		}
	}
}

void citire(){
	int x, y;
	
	for(int i=0; i<m; i++){
		f>>x>>y;
		f>>a[x][y];
	}		
}

/* DIJKSTRA */
int s[100], d[100], t[100];

void init_dijkstra(int n, int x){
	s[x] = 1;
	
	for(int i=1; i<=n; i++){
		d[i] = a[x][i];
		
		if(a[x][i] != INT_MAX && a[x][i] != 0){
			t[i] = x;
		}
	}
}

void dijkstra(int x){
	int minim = INT_MAX, p;
	
	for(int i=1; i<n; i++){
		minim = INT_MAX;
		for(int j=1; j<=n; j++){
			if(!s[j] && d[j] < minim){
				minim = d[j];
				p = j;
			}
		}
		
		s[p] = 1;
		
		if(minim == INT_MAX){
			return;
		}
		
		for(int j=1; j<=n; j++){
			if(d[p] + a[p][j] < d[j] && a[p][j] != INT_MAX){
				d[j] = d[p] + a[p][j];
				t[j] = p;
			}
		}
	}
}

void afisare(int x, int y){
	if(t[y] != 0){
		afisare(x, t[y]);
		cout<<y<<' ';
	}
	else{
		cout<<x<<' ';
	}
}

int main(){
	f>>n>>m;
	
	init_matrice();
	citire();
	f>>x;
	init_dijkstra(n, x);
	
	dijkstra(x);
	afisare(x, 1);
	
	f.close();
}