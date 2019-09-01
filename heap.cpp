#include <iostream>

using namespace std;

int n = 12; //nr de elemente
int a[] = {0, 10, 12, 7, 8, 18, 20, 15, 3, 9, 5, 42, 2};


//da-mi maximul intre doua pozitii din heap (in general intre 2*i si 2*i+1, copii unui nod)
int pmax(int i, int j){
	//daca j-ul e o frunza inexistenta (posibil in cazul in care nr de elemente este par)
	if(j > n){
		return i;
	}

	if(a[i] > a[j]){
		return i;
	}

	return j;
}

//insereaza un element la locul lui in heap
void down(int i){
	//verific ca i <= n/2 ca sa nu ies din vector cand fac a[2*i] si a[2*i+1]
	if(i <= n/2){

		if(a[i] > a[2*i] && a[i] > a[2*i+1]){
			//daca conditia heap-ului e indeplinita, inseamna ca a[i] e la locul potrivit
			return;
		}

		//conditia heap-ului nu e indepinita:

		//afla maximul dintre cei doi copii ai noduluio curent
		int p = pmax(2*i, 2*i+1);

		//schimba valoarea nodului curent cu maximul dintre copii
		swap(a[i], a[p]);

		//maximul acum e pe pozitia p
		//impinge mai departe elementul de pe pozitia p, in caz in care inca nu a ajuns la locul potrivit
		down(p);
	}
}

//sorteaza un heap
void heap_sort(){
	while(n > 1){
		swap(a[1], a[n]); //schimba elementul din radacina cu ultima frunza (cel mai mare cu cel mai mic)
		n--; //scade n-ul, pt. ca nu ma mai intereseaza ultima frunza
		down(1); //impinge elementul din radacina (acum cel mai mic) la locul lui

		//continua pana cand n-ul e mai mic ca 1 ca atunci am ajuns sa imping doar un element in heap, care sigur e la locul lui,
		// ca nu are copii care pot fi mai mari decat el
	}
}

int main(){
	//make heap
	//insereaza in heap, incep de la jumatate pt. ca down va verifica oricum elementele 2*i si 2*i+1, care sunt la "capat"
	for(int i=n/2; i>=1; i--){ 
		down(i);
	}

	for(int i=1; i<=n; i++){
		cout<<a[i]<< " ";
	}

	//salvez n-ul ca heap_sort mi-l modifica
	int m = n;
	heap_sort();
	n=m;

	cout<<"\nDupa heapSort:\n";
	for(int i=1; i<=n; i++){
		cout<<a[i]<< " ";
	}
}
