#include <iostream>
#include "singly_linked_list.h"

using namespace std;

void foo(){
    SinglyLinkedList sll;
    
    sll.push_back(5);
    sll.push_back(8);
    sll.push_back(10);
    
    sll.at(0) = 20;
    
    SinglyLinkedList sll2 = sll;
    sll2.push_back(3);
    sll2.push_back(2);
    
    sll2 = sll;
    
    for(int i = 0; i < sll2.size(); i++){
        cout << sll2.at(i) << endl;
    }
}

int main(){
    foo();
    foo();
    
    return 0;
}