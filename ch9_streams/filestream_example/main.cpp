#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    
    ifstream filestream;
    filestream.open("hello.txt");
    
    ofstream oFile;
    oFile.open("goodbye.txt", ios_base::app);
    
    string text;
    
    if(!filestream.is_open()){
        cout << "File is not open" << endl;
    }
    
    if(filestream.bad()){
        cout << "File is bad" << endl;
    }
    
    if(filestream.good()){
        cout << "File is good" << endl;
    }
    
    while(!filestream.eof() && filestream.is_open()){
        //filestream >> text;
        getline(filestream, text);
        oFile << text << "\n";
    }
    
    filestream.close();
    oFile.close();
    
    return 0;
}