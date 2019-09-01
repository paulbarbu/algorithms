#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

float f(float x){
	return x*x*x+x-1;
}

int main(){
	float eps, a[100], b[100], c[100], saprox;
	int k;
	ifstream in("in.txt");

	in>>a[0]>>b[0]>>eps;

	c[0]=(a[0]*f(b[0])-b[0]*f(a[0]))/(f(b[0])-f(a[0]));

	k=0;
	while(abs(f(c[k])) > eps){
		k++;
		if(f(a[k-1])*f(c[k-1]) <= 0){
			a[k] = a[k-1];
			b[k] = c[k-1];
		}
		else{
			a[k] = c[k-1];
			b[k] = b[k-1];
		}

		c[k] = (a[k]*f(b[k])-b[k]*f(a[k]))/(f(b[k])-f(a[k]));
	}

	saprox = c[k];

	cout<<"Saprox: "<<saprox<<"\nk:"<<k;
}