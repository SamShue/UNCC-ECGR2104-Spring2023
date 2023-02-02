#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

struct Complex{
    double real;
    double imag;
    
    Complex(double real, double imag);
    void print();
    Complex add(const Complex& c);
    Complex operator+(const Complex& c);
    Complex operator-(const Complex& c);
    void addToMyself(const Complex& c);
    void operator+=(const Complex& c);
};

#endif