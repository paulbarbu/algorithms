#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

struct nod{
	int val;
	nod *st, *dr;
};

int n, m, A[100][100], T[100];
bool viz[100];
nod *root;

void insert(nod *&p, int x){
	if(p == NULL){
		p = new nod;
		p->val = x;
		cout<<x<<" ";
		p->st = p->dr = NULL;
	}
	else{
		if(x < p->val){
			cout<<"s ";
			insert(p->st, x);
		}
		else{
			cout<<"d ";
			insert(p->dr, x);
		}
	}
}

void SRD(nod *p){
	if(p != NULL){
		SRD(p->st);
		cout<<p->val<<" ";
		SRD(p->dr);
	}
}

void RSD(nod *p){
	if(p != NULL){		
		cout<<p->val<<" ";
		RSD(p->st);
		RSD(p->dr);
	}
}

void SDR(nod *p){
	if(p != NULL){		
		SDR(p->st);
		SDR(p->dr);
		cout<<p->val<<" ";
	}
}

int nr_noduri(nod *p){
	if(p == NULL){
		return 0;
	}
	else{
		return 1+nr_noduri(p->st)+nr_noduri(p->dr);
	}
}

int adancime(nod *p, int a=-1){
	if(p == NULL){
		return a;
	}
	else{
		int a_st = adancime(p->st, a+1);
		int a_dr = adancime(p->dr, a+1);

		if(a_st > a_dr){
			return a_st;
		}
		else{
			return a_dr;
		}
	}
}

int nr_frunze(nod *p){
	if(p == NULL){
		return 0;
	}
	else{
		if(p->st == NULL && p->dr == NULL){
			return 1;
		}
		else{
			return nr_frunze(p->st) + nr_frunze(p->dr);
		}
	}
}

int minim(nod *p){
	if(p->st == NULL){
		return p->val;
	}
	else{
		return minim(p->st);
	}
}

int maxim(nod *p){
	if(p->dr == NULL){
		return p->val;
	}
	else{
		return maxim(p->dr);
	}
}

void eliminare(nod *&p, int x){
	if(p == NULL){
		cout << "Nu am gasit nod cu val " << x;
	}
	else if(x == p->val){
		if(p->st == NULL && p->dr == NULL){
			delete p;
			p = NULL;
			return;
		}

		if(p->dr == NULL){
			nod *q = p->st;
			delete p;
			p = q;
			return;
		}
		if(p->st == NULL){
			nod *q = p->dr;
			delete p;
			p = q;
			return;
		}

		int y = minim(p->dr);
		p->val = y;
		eliminare(p->dr, y);
	}
	else if(x < p->val){
		eliminare(p->st, x);
	}
	else{
		eliminare(p->dr, x);
	}
}

int main(){
	//srand(time(NULL));
	ifstream f("arbori.in");
	f>>n;

	for(int i=0; i<n; i++){
		int x;
		f>>x;
		insert(root, x);
	}

	cout<<"\nSRD: ";
	SRD(root);
	cout<<"\nRSD: ";
	RSD(root);
	cout<<"\nSDR: ";
	SDR(root);

	cout<<"\nadancime: "<<adancime(root);
	cout<<"\nnr_noduri: "<<nr_noduri(root);
	cout<<"\nnr_frunze: "<<nr_frunze(root);
	cout<<"\nminim: "<<minim(root);
	cout<<"\nmaxim: "<<maxim(root);
	cout<<"\n";
	eliminare(root, 2);
	cout<<"\nDupa eliminarea lui 2:\n";

	cout<<"\nSRD: ";
	SRD(root);
	cout<<"\nRSD: ";
	RSD(root);
	cout<<"\nSDR: ";
	SDR(root);
	cout<<"\nadancime: "<<adancime(root);
	cout<<"\nnr_noduri: "<<nr_noduri(root);
	cout<<"\nnr_frunze: "<<nr_frunze(root);
}
