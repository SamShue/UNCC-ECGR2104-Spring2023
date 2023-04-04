#include <iostream>

using namespace std;

class Person {
    public:
    Person(string name, int id){
        this->name = name;
        this->id = id;
    }
    
    void setName(string name){
        this->name = name;
    }
    
    string getName() const {
        return name;
    }
    
    void setId(int id){
        this->id = id;
    }
    
    int getId() const {
        return id;
    }
    
    void print(){
        cout << name << " " << id << endl;
    }
        
    protected:
    string name;
    int id;
};

class Student : public Person {
    public:
    Student(string name, int id, double gpa) : Person(name, id) {
        this->gpa = gpa;
    }
    
    void setGpa(double gpa){
        if(gpa >= 0.0 && gpa <= 4.0){
            this->gpa = gpa;
        }
    }
    
    double getGpa() const {
        return gpa;
    }
    
    void print(){
        cout << name << " " << id << " " << gpa << endl;
    }
    
    private:
    double gpa;
};

class Faculty : public Person {
    public:
    Faculty(string name, int id, double salary) : Person(name, id) {
        this->salary = salary;
    }
    
    void setSalary(double salary){
        if(salary >= 0.0){
            this->salary = salary;
        }
    }
    
    void print(){
        cout << name << " " << id << " " << salary << endl;
    }
    
    double getSalary() const {
        return salary;
    }
    
    private:
    double salary;
};

int main(){
    
    Student s("Sam", 800123123, 2.8);
    Faculty f("Conrad", 800234234, 120000);
    
    s.print();
    f.print();
    
    return 0;
}