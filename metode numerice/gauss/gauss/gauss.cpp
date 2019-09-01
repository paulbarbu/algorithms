#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n,i,j,k,p;
	float a[100][100],b[100],m,s,aux,x[100];
	
	cout<<"n= "; cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cout<<"a["<<i<<"]["<<j<<"]= ";
			cin>>a[i][j];
		}
	}
	for(i=1;i<=n;i++){
		cout<<"b["<<i<<"]= ";
		cin>>b[i];
	}
	for(i=1;i<=n;i++){
		a[i][n+1]=b[i];
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
				for(j=1;j<=n+1;j++){
					aux=a[p][j];
					a[p][j]=a[k][j];
					a[k][j]=aux;
				}
				
			}
			for(i=k+1;i<=n;i++){
				for(j=k+1;j<=n+1;j++){
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
		s=0;
		for(j=i+1;j<=n;j++){
			s=s+a[i][j]*x[j];
		}
		x[i]=(a[i][n+1]-s)/a[i][i];
	}
	for(i=1;i<=n;i++){
		cout<<"x["<<i<<"]="<<x[i]<< " ";
	}
}