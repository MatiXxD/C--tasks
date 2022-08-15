#include <iostream>
#include <ctype.h>

using namespace std;

int main(){

    char ch;
    
    cout << "Enter char value: ";
    cin >> ch;
    cout << islower(ch) << endl;

    return 0;

}