#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class SinglyLinkedList{
    public:
    SinglyLinkedList(){
        head = nullptr;
    }
    
    SinglyLinkedList(const SinglyLinkedList& rhs);
    
    ~SinglyLinkedList();
    
    void push_back(int data);
    void pop_back();
    int& at(int index) const;
    void insert(int index, int data);
    void remove(int index);
    int size() const;
    
    void operator=(const SinglyLinkedList& rhs);
    
    private:
    Node* head;
};

#endif