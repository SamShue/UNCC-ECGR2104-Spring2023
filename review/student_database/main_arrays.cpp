#include <iostream>

#define NAME 1000

using namespace std;

int main(){
    const int BASE_STUDENT_ID = 800000000;
    const int MAX_STUDENTS = 1000;
    
    string name[MAX_STUDENTS];
    int id[MAX_STUDENTS];
    double gpa[MAX_STUDENTS];
    
    int currentIndex = 0;
    
    string tempName, tempId, tempGpa;
    
    do{
        cout << "Enter the student name" << endl;
        getline(cin, tempName);
        cout << "Enter the student gpa" << endl;
        getline(cin, tempGpa);
        
        name[currentIndex] = tempName;
        id[currentIndex] = BASE_STUDENT_ID + currentIndex;
        gpa[currentIndex] = stod(tempGpa);
        
        currentIndex++;
        
        if(currentIndex >= MAX_STUDENTS)
            break;
        
        cout << "Enter more student names? (y/n):" << endl;
        getline(cin, tempName);
    }while(tempName == "y");
    
    for(int i = 0; i < currentIndex; i++){
        cout << name[i] << endl;
        cout << id[i] << endl;
        cout << gpa[i] << endl; 
    }
    
    return 0;
}