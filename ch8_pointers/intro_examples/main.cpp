#include <iostream>

using namespace std;
/*
void foo(int& z){
    z = 10;
}
*/
void foo(int* z){
    *z = 10;
}

int main(){
    int x = 1032;
    char c = 'A';
    
    int* p = &x;
    char* p2 = &c;
    
    foo(&x);
    
    cout << p << endl;
    cout << *p << endl;
    
    
    return 0;
}