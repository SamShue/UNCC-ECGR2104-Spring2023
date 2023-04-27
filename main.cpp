#include <iostream>

using namespace std;

class demo {
    
};

int main(){
    try{
        cout << "Will get here" << endl;
        throw demo();
        cout << "Will not get here" << endl;
    } catch (int x){
        cout << "Caught the thrown instance of demo" << endl;
    }
    
    
    return 0;
}