#include <iostream>
#include <fstream>

using namespace std;

ifstream f("arb.in");

struct nod{
	nod *st, *dr;
	int nr;
	int f;
} *rad;

void creare(nod *&rad, int x){
	if(rad){
		if(x < rad->nr){
			creare(rad->st, x);
		}
		else if(x > rad->nr){
			creare(rad->dr, x);
		}
		else{
			rad->f++;
		}
	}
	else{
		rad =  new nod;
		rad->st = rad->dr = NULL;
		rad->nr = x;
		rad->f = 1;
	}
}

void SRD(nod *r){ // in
	if(r != NULL){
		SRD(r->st);

		cout<<r->nr<<"("<<r->f<<")"<<" ";

		SRD(r->dr);
	}
}

void el_sterge_mx(nod *&p, nod*&q){
	if(q->dr){
		el_sterge_mx(p, q->dr);
	}
	else{
		nod *r = q->st;
		p->nr = q->nr;
		p->f = q->f;
		delete q;
		q = r;
	}
}

void sterge(nod *&r, int x){
	if(r){
		nod *p;

		if(x < r->nr){
			sterge(r->st, x);
		}
		else if(x > r->nr){
			sterge(r->dr, x);
		}
		else if(!r->st && !r->dr){
			p=r;
			delete p;
			r = NULL;
		}
		else if(!r->st){
			p = r->dr;
			delete r;
			r = p;
		}
		else if(!r->dr){
			p = r->st;
			delete r;
			r = p;
		}
		else{
			el_sterge_mx(r, r->st);
		}
	}
}

void sterge_el_cu_fr_x(nod *&r, int x){
	if(r){
		if(r->f >= x){
			sterge(r, r->nr);
		}

		sterge_el_cu_fr_x(r->st, x);
		sterge_el_cu_fr_x(r->dr, x);
	}
}

int main(){
	long long x;
	int fr;

	f>>fr>>x;

	while(x){
		creare(rad, x%10);
		x /= 10;
	}

	SRD(rad);
    cout<<"\n";

	sterge_el_cu_fr_x(rad, fr);

	SRD(rad);
    cout<<"\n";

	f.close();
}
