#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct node{
    int x;
    node *left, *right;
};

void create(node *&r, ifstream &f){
    int a;
    f>>a;

    if(a){
        r = new node;

        r->x = a;
        create(r->left, f);
        create(r->right, f);
    }
    else{
        r = NULL;
    }
}

int no_leaves(node *r){
    if(r){
        if(!r->left && !r->right){
            return 1;
        }
        else{
            return no_leaves(r->left) + no_leaves(r->right);
        }
    }

    return 0;
}

int no_nodes(node *r){
    if(r){
        return 1 + no_nodes(r->left) + no_nodes(r->right);
    }

    return 0;
}

void RSD(node *r){
    if(r){
        cout<<r->x;
        RSD(r->left);
        RSD(r->right);
    }
}

int even_nodes_sum(node *r){
    if(r){
        int t=0;

        if(r->x % 2 == 0){
            t = r->x;
        }

        return t + even_nodes_sum(r->left) + even_nodes_sum(r->right);
    }

    return 0;
}

bool is_prime(int x){
    if(x <= 1){
        return false;
    }

    for(int i=2; i<=sqrt(x); i++){
        if(x % i == 0){
            return false;
        }
    }

    return true;
}

int max_of_primes(node *r){
    int max = 0;

    if(r){
        if(is_prime(r->x)){
            max = r->x;
        }

        int left_max = max_of_primes(r->left);
        int right_max = max_of_primes(r->right);

        if(max < left_max){
            max = left_max;
        }

        if(max < right_max){
            max = right_max;
        }
    }

    return max;
}

int get_tree_height(node *r){
    int h = 0;

    if(r){
        if(!r->left && !r->right){
            return 0;
        }

        int left_h = get_tree_height(r->left);
        int right_h = get_tree_height(r->right);

        if(left_h > right_h){
            h = left_h + 1;
        }
        else{
            h = right_h + 1;
        }
    }

    return h;
}

int main(){
    node *r;
    ifstream f("trees.in");

    create(r, f);

    RSD(r);
    cout<<'\n'<<no_leaves(r)<<'\n';
    cout<<no_nodes(r)<<'\n';
    cout<<even_nodes_sum(r)<<'\n';
    cout<<max_of_primes(r)<<'\n';
    cout<<get_tree_height(r)<<'\n';

    f.close();
}
