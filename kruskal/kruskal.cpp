//multimi disjuncte - arbori
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct muchie{
	int n1, n2, cost;
};

int comp(muchie a, muchie b){
	if(a.cost < b.cost){
		return 1;
	}

	return 0;
}

muchie graf[6000], apm[101]; // un arbore are max n-1 muchii, iar graful are n(n-1)/2
int c[101], n, m, ct=0;

int main(){
	ifstream f("in.txt");
	f>>n>>m;

	for(int i=0; i<m; i++){ //citesc m muchii
		f>>graf[i].n1>>graf[i].n2>>graf[i].cost;
	}

	for(int i=1; i<=n; i++){
		c[i] = i;
	}

	sort(graf, graf+m, comp);

	for(int i=0; i<m; i++){
		int x = graf[i].n1;
		int y = graf[i].n2;
		if(c[x] != c[y]){
			apm[ct] = graf[i];
			ct++;
			int val = c[x];
			replace(c+1, c+n+1, val, c[y]); //inlocuim componenta conexa din care fac parte nodurile ca sa reflecte muchia adaugata

			if(ct==n-1){
				break;
			}
		}
	}

	int s=0;
	for(int i=0; i<ct; i++){
		cout<<apm[i].n1<<" "<<apm[i].n2<<" "<<apm[i].cost<< "\n";
		s+=apm[i].cost;
	}

	cout<<"ct: "<<ct<<" cost: "<<s;
}