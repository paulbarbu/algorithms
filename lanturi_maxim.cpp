#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int n, m, a[100][100], st[100], uz[100], x, y, maxim = INT_MIN, s[100];

int valid(int k){
	if(k == 1){
		return 1;
	}
		
	if(a[st[k]][st[k-1]]){
		return 1; //are legatura nodul curent cu cel precedent
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
	if(st[k] == y){
		return 1;
	}
	
	return 0;
}

void lanturi(int k){
	for(int i=1; i<=n; i++){
		st[k] = i;
		
		if(!uz[i] && valid(k)){
			uz[i] = 1;
			
			if(sol(k)){
				tip(k);
			}
			else{
				lanturi(k+1);
			}
			
			uz[i] = 0;
		}
	}
}

void lant_max(int k){
		for(int i=1; i<=n; i++){
		st[k] = i;
		
		if(!uz[i] && valid(k)){
			uz[i] = 1;
			
			if(sol(k)){
				if(k > maxim){
					maxim = k;
					
					for(int j=1; j<=k; j++){
						s[j] = st[j];
					}
				}
			}
			else{
				lant_max(k+1);
			}
			
			uz[i] = 0;
		}
	}
}



int main(){
	int z, v;
	ifstream f("f.in");
	
	f>>x>>y>>n>>m;
	
	for(int i=0; i<m; i++){
		f>>z>>v;
		a[z][v] = a[v][z] = 1;
	}
	
	st[1] = x;
	uz[x] = 1; 
	//lanturi(2);
	lant_max(2);

	for(int i=1; i<=maxim; i++){
		cout<<s[i]<<' ';
	}	
	cout<<"\n";
	
	f.close();
}