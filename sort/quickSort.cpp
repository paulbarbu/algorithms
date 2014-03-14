// g++ --std=c++11 -Wall quickSort.cpp
#include <vector>
#include <iostream>

template <typename T>
void qs(std::vector<T> &v, typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
    if(1 >= std::distance(start,end)){
        return;
    }

    auto mid = start;
    std::advance(mid, std::distance(start, end)/2);

    T pivot = *mid;
    auto left=start, right=end;

    while(1 <= std::distance(left, right)){
        while(1 < std::distance(left, right) && *left < pivot){
            left++;
        }

        while(1 <= std::distance(left, right) && *(right-1) > pivot){
            right--;
        }

        if(1 <= std::distance(left, right)){
            std::swap(*left, *(right-1));
            left++;
            right--;
        }
    }

    qs(v, start, right);
    qs(v, right, end);
}

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

template <typename T>
void qs(std::vector<T> &v, int start, int end){
    if(start >= end){
        return;
    }

    auto mid = (start+end)/2;
    T pivot = v[mid];
    int left=start, right=end;

    while(left < right){
        while(left < right && v[left] < pivot){
            left++;
        }

        while(right >= left && v[right] > pivot){
            right--;
        }

        if(left<right){
            std::swap(v[left], v[right]);
            left++;
            right--;
        }
    }

    qs(v, start, right);
    qs(v, right+1, end);
}

int main(){
    std::vector<int> foo;
    foo.push_back(2);
    foo.push_back(4);
    foo.push_back(1);
    foo.push_back(7);

    qs(foo, foo.begin(), foo.end());

    for(auto val : foo){
        std::cout<<val<<" ";
    }

    std::cout<<"\n";
}
