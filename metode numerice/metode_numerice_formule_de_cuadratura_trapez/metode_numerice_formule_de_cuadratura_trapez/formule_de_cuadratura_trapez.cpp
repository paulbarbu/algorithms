#include <iostream>
#include <fstream>

using namespace std;

float f(float x){
	return pow((float)2.71828183, -(x*x));
}

int main(){
	int n, a, b, i;
	float h, x[1000], Iaprox, S;
	ifstream in("trapez.in");

	in>>n>>a>>b;

	h = (float)(b-a)/n;
	for(i=1; i<=n-1; i++){
		x[i] = a+i*h;
	}

	S=0;
	for(i=1; i<=n-1; i++){
		S+=f(x[i]);
	}

	Iaprox = (h/2)*(f(a) + f(b)+2*S);

	cout<<"Iaprox = "<<Iaprox;
}