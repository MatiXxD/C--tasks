#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int pounds, shillings, pence;

    cout << "Enter pounds count: ";
    cin >> pounds;
    cout << "Enter shillings count: ";
    cin >> shillings;
    cout << "Enter pence count: ";
    cin >> pence;

    cout << "Decimal pounds: " << 'J' << pounds << '.'
        << round((12 * shillings + pence) / 2.4) << endl; 

    return 0;

}