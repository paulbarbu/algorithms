// g++ --std=c++11 -Wall quickSort.cpp
#include <vector>
#include <iostream>

template <typename T>
std::vector<T> qs(std::vector<T> v){
    std::vector<T> smaller, greater;
    T pivot;

    if(!v.size()){
        return smaller;
    }

    pivot = v.back();
    v.pop_back();

    for(T val : v){
        if(val <= pivot){
            smaller.push_back(val);
        }
        else{
            greater.push_back(val);
        }
    }

    smaller = qs(smaller);
    greater = qs(greater);

    smaller.push_back(pivot);
    smaller.insert(smaller.end(), greater.begin(), greater.end());

    return smaller;
}

int main(){
    std::vector<int> foo;
    foo.push_back(2);
    foo.push_back(4);
    foo.push_back(1);
    foo.push_back(7);
    foo = qs(foo);

    for(auto val : foo){
        std::cout<<val<<" ";
    }

    std::cout<<"\n";
}
