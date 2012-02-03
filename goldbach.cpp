#include <iostream>

using namespace std;

int main()
{
	int n, m=0, d=0, i, j, x, e;
	
	cout<<"Nr care vreti sa fie scris ca suma de 2 nr prime este:\n";
	cin>>n;
	
	for(i=2; i<n; i++)
	{
		x=i;
		for(j=1; j<=n/2; j++)
		{
			if(i%j==0)
				d++;
		}
		
		if(d==2)
		{
			if(m<x)
				m=x;
		}
	}
	e=n-m;
	cout<<"Nr scris ca suma de 2 nr prime este:"<<n<<"="<<m<<"+"<<e;
}
