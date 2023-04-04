#include <iostream>

using namespace std;

class Shape {
    public:
    Shape(double height, double width){
        this->height = height;
        this->width = width;
    }
    
    void print(){
        cout << "Should not be called" << endl;
    }
    
    protected:
    double height, width;
};

class Triangle : public Shape {
    public:
    Triangle(double height, double width) : Shape(height, width) { }
    
    void print(){
        cout << "Triangle" << endl << "height: " << height << " base: " << width << endl;
    }
    
    double getArea(){
        return 0.5 * height * width;
    }
};

class Rectangle : public Shape {
    public:
    Rectangle(double height, double width) : Shape(height, width) { }
    
    void print(){
        cout << "Rectangle" << endl << "height: " << height << " width: " << width << endl;
    }
    
    double getArea(){
        return height * width;
    }
};

class Square : public Rectangle {
    public:
    Square(double width) : Rectangle(width, width) { }
    
    void print(){
        cout << "Square" << endl << " width: " << width << endl;
    }
};

int main(){
    
    Rectangle r(5, 10);
    Triangle t(5, 7);
    Square s(10);
    
    r.print(); 
    cout << r.getArea() << endl;
    
    t.print();
    cout << t.getArea() << endl;
    
    s.print();
    cout << s.getArea() << endl;
    
    
    return 0;
}