/**
 * Binary search, this must be done on a sorted vector
 */
#include <fstream>

using namespace std;

int main()
{
	int n, a[100], x, s=0, d, gas=0, i, mjl;

	ifstream intrare("intrare.in");
	ofstream iesire("iesire.out");

	intrare>>x;
	intrare>>n;

	for(i=0; i<n; i++)
		intrare>>a[i];

	d=n-1;

	while(!gas && s<=d){
		mjl=(s+d)/2;
		if(x==a[mjl])
			gas=1;
		else if(x<a[mjl]){
			gas=1;
			d=mjl-1;
		}
		else
			s=mjl+1;
	}

	iesire<<mjl<<" "<<a[mjl];
}
