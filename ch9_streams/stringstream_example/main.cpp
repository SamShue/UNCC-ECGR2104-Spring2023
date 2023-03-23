#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main(){
    
    double dollars = 5.25;
    
    stringstream ss;
    
    ss << "$" << fixed << setprecision(2) << dollars/2.0 << " dollars";
    
    cout << ss.str() << endl;
    
    char temp;
    double value;
    string temp2;
    
    //ss >> temp;
    //ss >> value;
    ss >> temp2;
    
    //cout << temp << endl;
    //cout << value << endl;
    cout << temp2 << endl;
    
    return 0;
}