#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

const int INFINITY = INT_MAX/2;

int n, m; //nr de noduri si de muchii
int d[100], t[100], v[100];
int source;
int H[100][100];

void init(){
	for(int i=1; i<=n; i++){
		d[i] = H[source][i];

		if(H[source][i] != INFINITY){
			t[i] = source;
		}
		else{
			t[i] = -1;
		}
		t[source] = 0;

		if(i != source){
			v[i] = 0;
		}
		v[source] = 1;
	}
}

void dijkstra(){
	for(int i=1; i <=n-1; i++){
		int min = INFINITY;
		int p = -1; // nodul p da minimul
		for(int j=1; j<=n; j++){
			if(0 == v[j] && d[j] < min){
				min = d[j];
				p = j;
			}
		}
		v[p]=1;

		for(int j =1; j<=n; j++){
			if(0 == v[j] && d[j] > d[p] + H[p][j]){
				d[j] = d[p] + H[p][j];
				t[j] = p;
			}
		}
	}
}

void path(int dest){
	if(0 != dest){
		path(t[dest]);
		cout<< dest << " ";
	}
}

int main(){
	int x1, x2, c, dest;
	ifstream f("dijkstra.in");
	f>>source>>dest;
	f>>n>>m;

	for(int i = 1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j){
				H[i][j] = 0;
			}
			else{
				H[i][j] = INFINITY;
			}
		}
	}

	for(int i = 0; i<m; i++){
		f>>x1>>x2>>c;
		H[x1][x2] = c;
	}

	/*cout<<"H:\n";
	for(int i = 1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout.width(3);
			if(INFINITY == H[i][j]){
				cout<< "I" << " " ;
			}
			else{
				cout << H[i][j] << " ";
			}
		}
		
		cout<<"\n";
	}*/

	init();
	dijkstra();

	for(int i=1; i<=n; i++){
		cout.width(3);
		cout<<i<<" ";
	}
	cout<<"\nT:\n";
	for(int i=1; i<=n; i++){
		cout.width(3);
		cout<<t[i]<<" ";
	}
	cout<<"\n";
	cout<<"\nD:\n";
	for(int i=1; i<=n; i++){
		cout.width(3);
		cout<<d[i]<<" ";
	}

	cout<< "\nPath from " <<source << " to " << dest <<":\n";
	path(dest);
}