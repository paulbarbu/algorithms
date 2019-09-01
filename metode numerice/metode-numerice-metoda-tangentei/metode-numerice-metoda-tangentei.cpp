#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

float f(float x){
	return x*x*x+x*x+x-1;
}

float fd(float x){
	return 3*x*x+2*x+1;
}

int main(){
	float a, b, eps, saprox, x[1000];
	int k;
	ifstream in("in.txt");
	in>>a>>b>>eps;

	if(f(a)*(fd(a)-fd(b)) < 0){
		x[0] = a;
	}
	else{
		x[0] = b;
	}
	
	k=0;
	
	while(f(x[k]) >= eps){
		x[k+1] = x[k] - (f(x[k])/fd(x[k]));
		k++;
	}

	saprox = x[k];
	cout<<"k="<<k;
	cout<<"\nsaprox="<<saprox;
}