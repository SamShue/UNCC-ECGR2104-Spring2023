#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

namespace shue{

template<typename T>
class vector{
    public:
    vector();
    vector(const vector& rhs);
    ~vector();
    
    void operator=(const vector& rhs);
    void push_back(T val);
    void pop_back();
    T& at(int idx) const;
    int size();
    
    private:
    T* a;
    int nextIdx;
    int arraySize;
};

template<typename T>
vector<T>::vector(){
    nextIdx = 0;
    arraySize = 3;
    a = new T[arraySize];
}

template<typename T>
vector<T>::vector(const vector<T>& rhs){
    std::cout << "Copy Constructor called!" << std::endl;
    nextIdx = rhs.nextIdx;
    arraySize = rhs.arraySize;
    
    a = new T[arraySize];
    for(int i = 0; i < nextIdx; i++){
        a[i] = rhs.at(i);
    }
}
template<typename T>
vector<T>::~vector(){
    std::cout << "Destructor called!" << std::endl;
    delete[] a;
}

template<typename T>
void vector<T>::operator=(const vector& rhs){
    std::cout << "Assignment operator override called!" << std::endl;
    delete[] a;
    
    nextIdx = rhs.nextIdx;
    arraySize = rhs.arraySize;
    
    a = new T[arraySize];
    for(int i = 0; i < nextIdx; i++){
        a[i] = rhs.at(i);
    }
}

template<typename T>
void vector<T>::push_back(T val){
    if(nextIdx == arraySize){
        std::cout << "Reallocating more space..." << std::endl;
        T* temp = new T[arraySize*2];
        for(int i = 0; i < arraySize; i++){
            temp[i] = a[i];
        }
        delete[] a;
        a = temp;
        arraySize = arraySize * 2;
    }
    
    a[nextIdx] = val;
    nextIdx++;
}

template<typename T>
void vector<T>::pop_back(){
    nextIdx--;
}

template<typename T>
T& vector<T>::at(int idx) const{
    return a[idx];
}

template<typename T>
int vector<T>::size(){
    return nextIdx;
}

}

#endif