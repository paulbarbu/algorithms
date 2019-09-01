#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int main(){
	int n, i, j,r,k;
	float a[100][100], x[100], b[100], y[100], l[100][100], s;
	
	ifstream f("intrare.txt");
	
	f>>n;	
	for(i=1; i<=n; i++){
		for(j=1; j<=i; j++){
			f>>a[i][j];
			a[j][i] = a[i][j];
		}
	}	
	for(i=1; i<=n; i++){
		f>>b[i];
	}
	
	
	for(r=1;r<=n;r++){
		s=0;
		for(k=1; k<=r-1; k++){
			s+=l[r][k]*l[r][k];
		}
		
		l[r][r] = sqrt(a[r][r]-s);
		
		for(i=r+1; i<=n; i++){
			s=0;
			for(k=1; k<=r-1; k++){
				s+=l[i][k]*l[r][k];
			}
			l[i][r] = (a[i][r] - s)/l[r][r];
		}
	}
	
	for(i=1; i<=n; i++){
		s=0;
		for(j=1; j<=i-1; j++){
			s+=l[i][j]*y[j];
		}
		y[i] = (b[i] - s)/l[i][i];
	}
	
	for(i=n; i>=1; i--){
		s=0;
		for(j=i+1; j<=n; j++){
			s+=l[j][i]*x[j];
		}
		x[i] = (y[i] - s)/l[i][i];
	}
	
	for(i=1; i<=n; i++){
		cout<< "x["<<i<<"]="<<x[i]<<" ";
	}
}