#include <iostream>
#include <vector>

using namespace std;

class Student {
    public:
    Student(string n, int i, vector<double> g){
        cout << "Constructor called!" << endl;
        name = n;
        setId(i);
        
        for(int i = 0; i < g.size(); i++){
            addGrade(g.at(i));
        }
    }
    
    Student(string n, int i) : name(n) {
        cout << "Constructor called!" << endl;
        setId(i);
    }
    
    Student(){
        name = "Undefined";
        id = -1;
    }
    
    void setName(string n){
        name = n;
    }
    
    string getName() const {
        return name;
    }
    
    void addGrade(double g){
        if(g > 4.0 || g < 0.0){
            cout << "Invalid grade!" << endl;
            return;
        }
        
        grades.push_back(g);
    }
    
    vector<double> getGrades() const {
        return grades;
    }
    
    void setId(int x){
        if(x > 800000000)
            id = x;
        else{
            cout << "Invalid ID assigned" << endl;
            id = -1;
        }
    }
    
    int getId() const {
        return id;
    }
    
    double getGpa() const {
        if(grades.size() == 0){
            return 4.0;
        }
        
        double sum = 0.0;
        for(int i = 0; i < grades.size(); i++)
            sum = sum + grades.at(i);
        return sum/(double)grades.size();
    }
    
    private:
    int id;
    vector<double> grades;
    string name;
};

int main(){
    vector<Student> students;
    
    // Stand-in for collecting data from user
    vector<double> temp = {4.0, 3.0, 2.0, 33.0};
    Student s("Bob", 800000001, temp);
    //s.setName("Bob");
    //s.setId(800000001);
    //s.addGrade(3.0);
    //s.addGrade(4.0);
    
    Student s1("Joe", 7, temp);
    //s1.setName("Joe");
    //s1.setId(7);
    //s1.addGrade(3.0);
    //s1.addGrade(6.0);
    
    Student s2("Mary", 800000002);
    
    students.push_back(s);
    students.push_back(s1);
    students.push_back(s2);
    
    for(int i = 0; i < students.size(); i++){
        cout << students.at(i).getName() << endl;
        cout << students.at(i).getId() << endl;
        cout << students.at(i).getGpa() << endl;
    }
    
    /*
    vector<string> name;
    vector<int> id;
    vector<vector<double>> grades;
    
    name.push_back("Bob");
    id.push_back(800000001);
    vector<double> temp = {4.0, 3.0, 2.0, 3.0};
    grades.push_back(temp);
    
    name.push_back("Joe");
    id.push_back(800000002);
    vector<double> temp2 = {2.0, 2.0, 1.0, 3.0, 1.0, 2.0};
    grades.push_back(temp2);
    
    for(int i = 0; i < name.size(); i++){
        cout << name.at(i) << endl;
        cout << id.at(i) << endl;
        for(int j = 0; j < (grades.at(i)).size(); j++){
            cout << (grades.at(i)).at(j) << endl;
        }
        
        cout << average(grades.at(i)) << endl;
    }
    */
    return 0;
}

