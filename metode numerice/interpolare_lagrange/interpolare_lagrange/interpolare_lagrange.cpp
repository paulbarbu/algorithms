#include<iostream>
#include<fstream>
using namespace std;

int main(){
	int n, i, j;
	float x[50], y[50], c, faprox, s, p;
	ifstream f("fisier.txt");
	f >> n;
	f >> c;
	
	for(i=0;i<=n;i++){
		f>> x[i];
	}
	for(i=0;i<=n;i++){
		f>> y[i];
	}
	s=0;
	for(i=0;i<=n;i++){
		p=1;
		for(j=0;j<=n;j++){
			if(i!=j){
				p=p*(c-x[j])/(x[i]-x[j]);
			}
				
		}
		s=s+p*y[i];
	}
	faprox=s;
	cout << "faprox= " << faprox;
	
	
}