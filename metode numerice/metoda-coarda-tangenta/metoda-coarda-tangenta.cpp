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
	float eps, s[100], t[100], saprox, a, b;
	int k;
	ifstream in("in.txt");

	in>>a>>b>>eps;

	if(f(a)*(fd(a)-fd(b)) < 0){
		s[0] =a;
		t[0] = b;
	}
	else{
		s[0] = b;
		t[0] = a;
	}
	k=0;

	while(abs(s[k]-t[k]) >= eps){
		k++;
		s[k] = (s[k-1]*f(t[k-1]) - t[k-1]*f(s[k-1]))/(f(t[k-1])-f(s[k-1]));
		t[k] = t[k-1] - f(t[k-1])/fd(t[k-1]);
	}
	saprox = (s[k]+t[k])/2;

	cout<<"Saprox: "<<saprox<<"\nk:"<<k;
}