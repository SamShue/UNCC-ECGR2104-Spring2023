#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> name;
    vector<int> id;
    vector<double> gpa;
    
    int nextId = 0;
    
    string tempName, tempGpa;
    
    do{
        cout << "Enter the student name" << endl;
        getline(cin, tempName);
        cout << "Enter the student gpa" << endl;
        getline(cin, tempGpa);
        
        name.push_back(tempName);
        id.push_back(800000000 + nextId);
        gpa.push_back(stod(tempGpa));
        
        nextId++;
        
        cout << "Enter more student names? (y/n):" << endl;
        getline(cin, tempName);
    } while(tempName == "y");
    
    for(int i = 0; i < name.size(); i++){
        cout << name.at(i) << endl;
        cout << id.at(i) << endl;
        cout << gpa.at(i) << endl; 
    }
    
    return 0;
}