#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

float f(float x){
	return pow((float)2.71828183, -(x*x));
}

int main(){
	int n, a, b, i;
	float h, x[1000], Iaprox, S, y[1000], S1;
	ifstream in("trapez.in");

	in>>n>>a>>b;

	h = (float)(b-a)/n;
	for(i=1; i<=n-1; i++){
		x[i] = a+i*h;
	}
	
	for(i=1; i<=n; i++){
		y[i] = a+(i-0.5)*h;
	}

	S=0;
	for(i=1; i<=n-1; i++){
		S+=f(x[i]);
	}

	S1=0;
	for(i=1; i<=n; i++){
		S1+=f(y[i]);
	}

	Iaprox = (h/6)*(f(a) + f(b)+2*S+4*S1);

	cout<<"Iaprox = "<<Iaprox;
}