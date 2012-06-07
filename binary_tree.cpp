#include <fstream>
#include <iostream>

using namespace std;

ifstream f("arbore.in");

struct nod{
	int nr;
	nod *st, *dr;
};
nod *r;

int t;

void creare(nod *&r){
	int x;
	f>>x;
	
	if(x == 0){
		r = NULL;
	}
	else{
		r = new nod;
		r->nr = x;
		
		creare(r->st);
		creare(r->dr);
	}
}

void RSD(nod *r){ // pre
	if(r != NULL){
		cout<<r->nr<<" ";

		RSD(r->st);
		RSD(r->dr);
	}
}

void SRD(nod *r){ // in
	if(r != NULL){
		SRD(r->st);
		
		cout<<r->nr<<" ";
		
		SRD(r->dr);
	}
}

void SDR(nod *r){ // post
	if(r != NULL){
		SDR(r->st);		
		SDR(r->dr);
		
		cout<<r->nr<<" ";
	}
}

void afis_noduri_de_pe_k(nod *r, int k, int c=1){
	if(r){
		if(c+1 == k){
			cout<<r->st->nr<<" "<<r->dr->nr;
		}
		else{
			afis_noduri_de_pe_k(r, k, c+1);
		}
	}
}

int main(){
	creare(r);
	/*
	cout<<"RSD: ";
	RSD(r);
	
	cout<<"\nSRD: ";
	SRD(r);
	
	cout<<"\nSDR: ";
	SDR(r);
	*/
	
	//cout<<contine_cif(425, 2);
	//cout<<produs(r);
	afis_noduri_de_pe_k(r, 2);
	
	f.close();
}