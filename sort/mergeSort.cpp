// g++ --std=c++11 -Wall quickSort.cpp
#include <iostream>
#include <algorithm>
#include <vector>

template<class T>
std::vector<T> mergeSort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
    if(start == end){
        return std::vector<T>();
    }

    if(1 == std::distance(start, end)){
        return std::vector<T>(1, *start);
    }

    auto mid = start;
    std::advance(mid, std::distance(start, end)/2);

    auto left = mergeSort<T>(start, mid);
    auto right = mergeSort<T>(mid, end);

    std::vector<T> result(left.size() + right.size(), 0);

    merge(left.begin(), left.end(), right.begin(), right.end(), result.begin());

    return result;
}

int main()
{
    std::vector<int> a;
    a.push_back(3);
    a.push_back(-1);
    a.push_back(1);
    a.push_back(5);

    auto r = mergeSort<int>(a.begin(), a.end());

    for(auto i=r.begin(); i != r.end(); i++){
        std::cout<<*i<<" ";
    }

    return 0;
}
