#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

const int INFINITY = INT_MAX/2;

int n, m; //nr de noduri si de muchii
int H[100][100], P[100][100];

void roy_floyd()
{
	for(int k=1;k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i!=j && j!=k && i!=k){
					//relaxare
					if(H[i][j] > H[i][k] + H[k][j]){
						P[i][j] = P[k][j]; // predecesorul lui j pe drumul de la i la j este k
						H[i][j] = H[i][k] + H[k][j];
					}
				}
			}
		}
	}
}

void path(int s, int d){
	if(0 != P[s][d]){
		path(s, P[s][d]);
		cout<<P[s][d]<<" ";
	}
}

int main(){
	int x1, x2, c, source;
	ifstream f("roy_floyd.txt");
	f>>source;
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
		P[x1][x2] = x1;
	}

	roy_floyd();


	cout<<"H:\n";
	for(int i = 1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout<<H[i][j]<<" ";
		}
		cout<<"\n";
	}

	cout<<"\nP:\n";
	for(int i = 1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout<<P[i][j]<<" ";
		}
		cout<<"\n";
	}

	for(int i=1; i<=n; i++){
		cout<<"\n H from "<<source<<" to "<<i<<": "<<H[source][i];
		cout<<"\nPath from "<<source<<" to "<<i<<": ";
		path(source, i);
		cout<<i;
	}
}