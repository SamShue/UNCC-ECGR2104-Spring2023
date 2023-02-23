#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

void push_back(Node*& head, int data){
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

void pop_back(Node*& head){
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

int at(Node* head, int index){
    Node* currentNode = head;
    int i = 0;
    while(i < index){
        currentNode = currentNode->next;
        i++;
    }
        
    return currentNode->data;
}

void insert(Node*& head, int index, int data){
    
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

void remove(Node*& head, int index){
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

int main(){
    Node* head = nullptr;
    
    push_back(head, 2);
    push_back(head, 10);
    push_back(head, 3);
    push_back(head, 40);
    
    remove(head,1);
    
    cout << at(head, 0) << endl;
    cout << at(head, 1) << endl;
    cout << at(head, 2) << endl;

    /*
    head = new Node;
    
    head->data = 2;
    head->next = nullptr;
    
    (head->next) = new Node;
    (head->next)->next = nullptr;
    (head->next)->data = 10;
    */
    
    return 0;
}