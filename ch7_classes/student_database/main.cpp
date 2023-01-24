#include <iostream>
#include <vector>

using namespace std;

double average(vector<double> v);

class Student {
    public:
    string name;
    
    void addGrade(double g){
        if(g > 4.0 || g < 0.0){
            cout << "Invalid grade!" << endl;
            return;
        }
        
        grades.push_back(g);
    }
    
    vector<double> getGrades(){
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
    
    int getId(){
        return id;
    }
    
    private:
    int id;
    vector<double> grades;
};

int main(){
    vector<Student> students;
    
    // Stand-in for collecting data from user
    Student s;
    s.name = "Bob";
    s.setId(800000001);
    s.addGrade(3.0);
    s.addGrade(4.0);
    
    Student s1;
    s1.name = "Joe";
    s1.setId(7);
    s1.addGrade(3.0);
    s1.addGrade(6.0);
    
    students.push_back(s);
    students.push_back(s1);
    
    for(int i = 0; i < students.size(); i++){
        cout << students.at(i).name << endl;
        cout << students.at(i).getId() << endl;
        cout << average(students.at(i).getGrades()) << endl;
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

double average(vector<double> v){
    double sum = 0.0;
    for(int i = 0; i < v.size(); i++)
        sum = sum + v.at(i);
    return sum/(double)v.size();
}

