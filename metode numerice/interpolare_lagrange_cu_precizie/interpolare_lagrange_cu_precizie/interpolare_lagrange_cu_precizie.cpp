#include<iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
	ifstream in("intrare.txt");	
	int n, i, j, grad;
	float x[50], y[50], c, faprox, eps, f[50][50];
	
	in>>n;
	in>>c;
	in>>eps;
	
	for(i=0;i<=n;i++){
		in >> x[i];
	}
	
	for(i=0;i<=n;i++){
		in >> y[i];
	}
	
	for(i=0; i<=n; i++){
		f[i][0] = y[i];
	}
	
	for(j=0; j<=n-1; j++){
		for(i=j+1; i<=n; i++){
			f[i][j+1] = ((c-x[i])*f[i-1][j] - (c-x[i-j-1])*f[i][j])/(x[i-j-1]-x[i]);
		}
	}
	i=1;
	
	while(fabs(f[i][i]-f[i-1][i-1]) > eps && i<=n){
		i++;
	}
	
	if(i<=n){
		faprox = f[i][i];
		grad=i;
		cout << "faprox= " << faprox << "\ngrad=" << grad;
	}
	else{
		cout<< "Nu s-a putut determina val aprox. cu precizia ceruta!";
	}
	in.close();
}