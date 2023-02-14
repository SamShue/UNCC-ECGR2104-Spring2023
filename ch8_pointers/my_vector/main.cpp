#include <iostream>

using namespace std;

class MyVector{
    public:
    MyVector(){
        nextIdx = 0;
        arraySize = 3;
        a = new int[arraySize];
    }
    
    void push_back(int val){
        if(nextIdx == arraySize){
            cout << "Reallocating more space..." << endl;
            int* temp = new int[arraySize*2];
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
    
    void pop_back(){
        nextIdx--;
    }
    
    int at(int idx){
        return a[idx];
    }
    
    int size(){
        return nextIdx;
    }
    
    private:
    int* a;
    int nextIdx;
    int arraySize;
};

int main(){
    MyVector v;
    
    v.push_back(10);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);
    v.push_back(10);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);
    
    v.pop_back();
    v.pop_back();
    
    v.push_back(20);
    
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }
    
    return 0;
}