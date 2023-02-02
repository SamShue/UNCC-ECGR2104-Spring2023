#include <iostream>
#include "complex.h"

using namespace std;

int main(){
    
    Complex c1(3.0, 5.0);
    Complex c2(2.5, 1.5);
    
    c1.print();
    c2.print();
    
    Complex c4(0,0);
    
    //c4.real = c1.real + c2.real;
    //c4.imag = c1.imag + c2.imag;
    
    c4 = c1.add(c2);
    c4 = c1 + c2;
    
    c4.addToMyself(c1);
    c4 += c1;
    
    c4.print();
    
    return 0;
}