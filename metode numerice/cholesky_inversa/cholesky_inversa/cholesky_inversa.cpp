#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int main(){
	int n, i, j,r,k,t;
	float a[100][100], x[100][100], b[100][100], y[100][100], l[100][100], s;
	
	ifstream f("intrare.txt");
	
	f>>n;	
	for(i=1; i<=n; i++){
		for(j=1; j<=i; j++){
			f>>a[i][j];
			a[j][i] = a[i][j];
		}
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(i==j){
				b[i][j]=1;
			}
			else{
				b[i][j]=0;
			}
		}
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
	
	for(t=1;t<=n;t++){
		for(i=1; i<=n; i++){
			s=0;
			for(j=1; j<=i-1; j++){
				s+=l[i][j]*y[j][t];
			}
			y[i][t] = (b[i][t] - s)/l[i][i];
		}
		
		for(i=n; i>=1; i--){
			s=0;
			for(j=i+1; j<=n; j++){
				s+=l[j][i]*x[j][t];
			}
			x[i][t] = (y[i][t] - s)/l[i][i];
		}
	}
	
	for(i=1; i<=n; i++){		
		for(j=1; j<=n; j++){
			cout.width(10);
			cout<< x[i][j]<<" ";
		}
		cout<<"\n";
	}
}