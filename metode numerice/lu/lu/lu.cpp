#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream f("intrare.txt");
	int n, r, i, j, k;
	float a[100][100], b[100], u[100][100],x[100], l[100][100], y[100],s;
	
	f>>n;
	
	for(i=1; i<=n; i++){
		f>>u[i][i];
	}	
	
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			f>>a[i][j];
		}
	}
	
	for(i=1; i<=n; i++){
		f>>b[i];
	}
	
	for(r=1; r<=n; r++){
		for(i=r; i<=n; i++){
			s=0;
			for(k=1; k<=r-1; k++){
				s = s+l[i][k]*u[k][r];
			}
			
			l[i][r] = (a[i][r] - s)/u[r][r];
		}
		
		for(j=r+1; j<=n; j++){
			s=0;
			for(k=1; k<=r-1; k++){
				s = s+l[r][k]*u[k][j];
			}
			
			if(l[r][r]==0){
				cout<<"Nu se pot determina solutiile";
				exit(0);
			}
			
			u[r][j] = (a[r][j] - s)/l[r][r];
		}
	}
	
	for(i=1; i<=n; i++){
		s=0;
		for(j=1; j<=i-1; j++){
			s = s+l[i][j]*y[j];
		}
			
		y[i] = (b[i] - s)/l[i][i];
	}
	
	for(i=n; i>=1; i--){
		s=0;
		for(j=i+1; j<=n; j++){
			s = s+u[i][j]*x[j];
		}
			
		x[i] = (y[i] - s)/u[i][i];
	}
	
	for(i=1; i<=n; i++){
		cout<< "x["<<i<<"]="<<x[i]<<" ";
	}
}