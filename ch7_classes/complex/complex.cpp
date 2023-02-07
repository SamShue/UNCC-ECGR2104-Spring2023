#include "complex.h"

using namespace std;

void foo(){
    cout << "Hello" <<endl;
}

Complex::Complex(double real, double imag){
    this->real = real;
    this->imag = imag;
}

void Complex::print(){
    cout << real << " + " << imag << "i" << endl;
}

Complex Complex::add(const Complex& c){
    Complex result(0,0);
    result.real = real + c.real;
    result.imag = imag + c.imag;
    return result;
}

Complex Complex::operator+(const Complex& c){
    Complex result(0,0);
    result.real = real + c.real;
    result.imag = imag + c.imag;
    return result;
}

Complex Complex::operator-(const Complex& c){
    Complex result(0,0);
    result.real = real - c.real;
    result.imag = imag - c.imag;
    return result;
}

void Complex::addToMyself(const Complex& c){
    real += c.real;
    imag += c.imag;
}

void Complex::operator+=(const Complex& c){
    real += c.real;
    imag += c.imag;
}