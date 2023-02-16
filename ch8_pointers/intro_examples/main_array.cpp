#include <iostream>

using namespace std;

int main(){
    int a[] = {1, 2, 3};
    int b = 4;
    int c = 5;
    int d = 6;
    
    cout << a << endl;
    cout << a + 1 << endl;
    cout << &a[2] << endl;
    cout << &b << endl;
    cout << &c << endl;
    cout << &d << endl;
    
    int* p = new int[10];
    p[2] = 5;
    delete[] p;
    
    
    cout << a[2] << endl;
    cout << *(a + 2) << endl;
    
    return 0;
}