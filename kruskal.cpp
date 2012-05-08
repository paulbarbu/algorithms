#include <iostream>
#include <fstream>

using namespace std;

int m, n, c=0, a[100][100];

ifstream f("graf.txt");

struct muchie{
	int x, y, c;
} v[100];

int l[100];

void citire(){
	int x, y;
	
	for(int i=0; i<m; i++){
		f>>v[i].x>>v[i].y>>v[i].c;
	}		
}

void ordonare_muchii(){
	muchie t;
	
	for(int i=0; i<m-1; i++){
		for(int j=i+1; j<m; j++){
			if(v[i].c > v[j].c){
				t = v[i];
				v[i] = v[j];
				v[j] = t;
			}
		}
	}
}

void kruskal(){
	int i, ct=0, comp1, comp2;
	for(i=0; i<n; i++){
		l[i] = i;
	}
	
	i=-1;
	while(ct<n-1){
		i++;
		comp1 = l[v[i].x];
		comp2 = l[v[i].y];
		
		if(comp1 != comp2){
			ct++;
			
			c+=v[i].c;
			
			a[v[i].x][v[i].y] = v[i].c;
			a[v[i].y][v[i].x] = v[i].c;
			
			for(int j=0; j<n; j++){
				if(l[j] == comp2){
					l[j] = comp1;
				}
			}
		}
	}
}

void afisare(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout<<a[i][j]<<' ';
		}			
		cout<<"\n";
	}
}

int main(){
	f>>n>>m;
	
	citire();
	ordonare_muchii();
	
	kruskal();
	
	afisare();
	
	cout<<"Cost: "<<c;
	
	f.close();
}