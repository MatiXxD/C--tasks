#include <iostream>

using namespace std;

int main(){

    int pounds, pence;
    char trash;

    cout << "Enter number of decimal pounds (pounds.pence): ";
    cin >> pounds >> trash >> pence;
    pence *= 2.4;

    cout << "The equivalent amount in the old form: " << 'J' << pounds
        << '.' << pence / 12 << '.' << pence % 12 << endl;

    return 0;

}