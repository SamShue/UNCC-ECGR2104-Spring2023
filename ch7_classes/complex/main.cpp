// 3 + 5i

#include <iostream>

using namespace std;

class Complex{
    public:
    double real;
    double imag;
    
    Complex(double r, double i){
        real = r;
        imag = i;
    }
    
    void print(){
        cout << real << " + " << imag << "i" << endl;
    }
    
    
    Complex add(const Complex& c){
        Complex result(0,0);
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }
    
    Complex operator+(const Complex& c){
        Complex result(0,0);
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }
    
    Complex operator-(const Complex& c){
        Complex result(0,0);
        result.real = real - c.real;
        result.imag = imag - c.imag;
        return result;
    }
    
    void addToMyself(const Complex& c){
        real += c.real;
        imag += c.imag;
    }
    
    void operator+=(const Complex& c){
        real += c.real;
        imag += c.imag;
    }
    
};

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