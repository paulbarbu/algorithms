#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

float f(float x){
	return pow((float)2.71828183, -(x*x));
}

int main(){
	int n, a, b, i;
	float h, Iaprox, y[1000], S1;

	cin>>n>>a>>b;

	h = (float)(b-a)/n;
	
	for(i=1; i<=n; i++){
		y[i] = a+(i-0.5)*h;
	}

	S1=0;
	for(i=1; i<=n; i++){
		S1+=f(y[i]);
	}

	Iaprox = h*S1;

	cout<<"Iaprox = "<<Iaprox;
}