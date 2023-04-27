#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

class MyVector{
    public:
    MyVector(){
        nextIdx = 0;
        arraySize = 3;
        a = new int[arraySize];
    }
    
    MyVector(const MyVector& rhs){
        cout << "Copy Constructor called!" << endl;
        nextIdx = rhs.nextIdx;
        arraySize = rhs.arraySize;
        
        a = new int[arraySize];
        for(int i = 0; i < nextIdx; i++){
            a[i] = rhs.at(i);
        }
    }
    
    ~MyVector(){
        cout << "Destructor called!" << endl;
        delete[] a;
    }
    
    void operator=(const MyVector& rhs){
        cout << "Assignment operator override called!" << endl;
        delete[] a;
        
        nextIdx = rhs.nextIdx;
        arraySize = rhs.arraySize;
        
        a = new int[arraySize];
        for(int i = 0; i < nextIdx; i++){
            a[i] = rhs.at(i);
        }
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
    
    int& at(int idx) const{
        stringstream ss;
        ss << "Index " << idx << " not within range";
        throw std::out_of_range(ss.str());
        return a[idx];
    }
    
    int size(){
        return nextIdx;
    }
    
    int* a;
    
    private:
    
    int nextIdx;
    int arraySize;
};


void makesProblem(){
    MyVector v;
    
    v.push_back(10);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);
    
    v.pop_back();
    v.pop_back();
    
    v.push_back(20);
    v.at(30) = 40;
    
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }
    
    MyVector v2;
    v2.push_back(10);
    v2.push_back(8);
    v2.push_back(5);
    v2.push_back(7);
    
    v2 = v;
    
    for(int i = 0; i < v2.size(); i++){
        cout << v2.at(i) << endl;
    }
    
    MyVector v3 = v;
    
    cout << "End of function call!" << endl;
}

int main(){
    
    try {
        makesProblem();
        
        makesProblem();
        
        makesProblem();
    } catch (const exception& e){
        cout << "Caught the exception!" << endl;
        cout << e.what() << endl;
    }

    
    return 0;
}