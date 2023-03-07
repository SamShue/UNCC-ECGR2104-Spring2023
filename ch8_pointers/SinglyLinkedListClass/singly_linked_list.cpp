#include "singly_linked_list.h"

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& rhs){
    cout << "Copy constructor called!" << endl;
    head = nullptr;
    for(int i = 0; i < rhs.size(); i++){
        push_back(rhs.at(i));
    }
}

void SinglyLinkedList::operator=(const SinglyLinkedList& rhs){
    cout << "Copy assignment override called!" << endl;
    // free the original list
    while(head != nullptr){
        Node* temp = head->next;
        delete head;
        head = temp;
    }
    // copy rhs list
    for(int i = 0; i < rhs.size(); i++){
        push_back(rhs.at(i));
    }
}

SinglyLinkedList::~SinglyLinkedList(){
    cout << "Destructor called!" << endl;
    while(head != nullptr){
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}

void SinglyLinkedList::push_back(int data){
    if(head == nullptr){
        head = new Node;
        head->data = data;
        head->next = nullptr;
        return;
    }
    
    Node* currentNode = head;
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    
    (*currentNode).next = new Node;
    (currentNode->next)->next = nullptr;
    (currentNode->next)->data = data;
}

void SinglyLinkedList::pop_back(){
    Node* currentNode = head;
    
    // No elements in list
    if(head == nullptr){
        return;
    }
    
    // 1 element in list
    if(currentNode->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    
    while(currentNode->next->next != nullptr){
        currentNode = currentNode->next;
    }
    
    delete currentNode->next;
    currentNode->next = nullptr;
    
}

int& SinglyLinkedList::at(int index) const{
    Node* currentNode = head;
    int i = 0;
    while(i < index){
        currentNode = currentNode->next;
        i++;
    }
        
    return currentNode->data;
}

void SinglyLinkedList::insert(int index, int data){
    
    if(index == 0){
        Node* temp = head;
        head = new Node;
        head->data = data;
        head->next = temp;
        return;
    }
    
    Node* currentNode = head;
    int i = 0;
    while(i < index - 1){
        currentNode = currentNode->next;
        i++;
    }
    
    Node* temp = currentNode->next;
    currentNode->next = new Node;
    currentNode->next->data = data;
    currentNode->next->next = temp;
}

void SinglyLinkedList::remove(int index){
    if(index == 0){
        Node* temp = head->next;
        delete head;
        head = temp;
        return;
    }
    
    Node* currentNode = head;
    int i = 0;
    while(i < index - 1){
        currentNode = currentNode->next;
        i++;
    }
    
    Node* temp = currentNode->next->next;
    delete currentNode->next;
    currentNode->next = temp;
}

int SinglyLinkedList::size() const{
    Node* temp = head;
    int count = 0;
    
    if(temp == nullptr){
        return count;
    }
    
    while(temp != nullptr){
        temp = temp->next;
        count++;
    }
    
    return count;
}