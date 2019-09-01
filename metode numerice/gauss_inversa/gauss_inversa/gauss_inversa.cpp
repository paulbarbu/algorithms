#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n,i,j,k,p,l;
	float a[100][100],b[100][100],m,s,aux,x[100][100];
	
	cout<<"n= "; cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cout<<"a["<<i<<"]["<<j<<"]= ";
			cin>>a[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				b[i][j]=1;
			}
			else{
				b[i][j]=0;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			a[i][n+j]=b[i][j];
		}
	}
	
	for(k=1;k<=n-1;k++){
		m=fabs(a[k][k]);
		p=k;
		for(i=k+1;i<=n;i++){
			if(fabs(a[i][k])>n){
				m=fabs(a[i][k]);
				p=i;
			}
		}
		if(a[p][k]!=0){
			if(p!=k){
				for(j=1;j<=n+n;j++){
					aux=a[p][j];
					a[p][j]=a[k][j];
					a[k][j]=aux;
				}				
			}
			for(i=k+1;i<=n;i++){
				for(j=k+1;j<=n+n;j++){
					a[i][j]=a[i][j]-(a[i][k]*a[k][j]/a[k][k]);
				}
				a[i][k]=0;
			}
		}
		else{
			cout<<"Sistemul nu poate fi rezolvat";
		return 0 ;
		}
		
	}
	for(i=n;i>=1;i--){
		for(l=1;l<=n;l++){
			s=0;
			for(j=i+1;j<=n;j++){
				s=s+a[i][j]*x[j][l];
			}
			x[i][l]=(a[i][n+l]-s)/a[i][i];
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cout<<x[i][j]<< " ";
		}
		cout<<endl;
	}
}
