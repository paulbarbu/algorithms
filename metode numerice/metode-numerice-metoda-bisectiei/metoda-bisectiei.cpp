#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

float f(float x){
	return x*x*x+x-1;
}

int main(){
	float a[1000], b[1000], c[1000], eps, saprox;
	int n=0, k;
	ifstream in("in.txt");
	in>>a[0]>>b[0]>>eps;

	while((b[0]-a[0])/pow(2.0, n) >= eps){
		n++;
	}

	c[0] = (a[0]+b[0])/2;

	for(k=1; k<=n; k++){
		if(f(a[k-1])*f(c[k-1])<=0){
			a[k] = a[k-1];
			b[k] = c[k-1];
		}
		else{
			a[k] = c[k-1];
			b[k] = b[k-1];
		}

		c[k] = (a[k]+b[k])/2;
	}

	saprox = c[n];
	cout<<"n="<<n;
	cout<<"\nsaprox="<<saprox;
}