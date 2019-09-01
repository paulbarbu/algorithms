//1.
//n si m
//x y noduri adiacente
//matr de adiacenta
//fct cu 2 param x, y care ret val 1 daca x si y sunt adiacente
//fct cu param x care ret gradul nodului x
//fct care afiseaza nodurile terminale (grad 1)

//2. Liste de adiacenta (std::list, std::vector)

#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> l[101];
int viz[101];

void print_l_adiacenta(vector<int> v){
	for(unsigned int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout<<"\n";
}

void print_l_adiacenta_all(int n, vector<int> v[]){
	for(int i=1; i<=n; i++){
		cout << i << ": ";
		print_l_adiacenta(v[i]);
	}
	cout<<"\n";
}

int grad(int nod){
	return l[nod].size()-1;
}

bool adiacente(int x, int y){
	vector<int>::iterator it;
	it = find(l[x].begin(), l[x].end(), y);

	if(it != l[x].end()){
		return true;	
	}
	return false;
}

void DFS(int nod){
	viz[nod]=1;
	cout << nod << " ";
	for(int i=0; i<l[nod].size(); i++){
		if(!viz[l[nod][i]]){
			viz[l[nod][i]] = 1;
			DFS(l[nod][i]);
		}
	}
}

bool isConex(int n){
	int ct=0;
	for(int i=0; i<101; i++){
		if(viz[i] == 1){
			ct++;
		}
	}

	if(ct == n){
		return true;
	}

	return false;
}

int main(){
	int n, m, x, y;

	ifstream f("in.txt");
	f>>n>>m;

	for(int i=0; i<m; i++){
		f>>x>>y;
		l[x].push_back(y);
		l[y].push_back(x);
	}

	cout << "L de adiacenta a lui 2: ";
	print_l_adiacenta(l[2]);

	cout << "\n";
	print_l_adiacenta_all(n, l);

	cout << "DFS(2): ";
	DFS(2);

	cout << "\nE conex? " << isConex(n);

	cout << "\nGrad(2): " << grad(2);

	cout << "\nadiacente(2, 3): " << adiacente(2, 3);
	cout << "\nadiacente(1, 3): " << adiacente(1, 3);
}

