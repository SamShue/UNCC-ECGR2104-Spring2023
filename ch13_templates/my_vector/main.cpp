#include <iostream>
#include <vector>
#include "vector.h"

void makesProblem(){
    shue::vector<double> v;
    
    shue::v.push_back(10);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);
    
    v.pop_back();
    v.pop_back();
    
    v.push_back(20);
    v.at(0) = 40;
    
    for(int i = 0; i < v.size(); i++){
        std::cout << v.at(i) << std::endl;
    }
    
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(8);
    v2.push_back(5);
    v2.push_back(7);
    
    for(int i = 0; i < v2.size(); i++){
        std::cout << v2.at(i) << std::endl;
    }
    
    vector<double> v3 = v;
    
    std::cout << "End of function call!" << std::endl;
}

int main(){
    
    makesProblem();
    
    makesProblem();
    
    makesProblem();

    
    return 0;
}