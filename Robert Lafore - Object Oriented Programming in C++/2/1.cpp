#include <iostream>

using namespace std;

int main(){

    const float COEF = 7.481F;
    float gallons; 

    cout << "Enter numbers of gallons: ";
    cin >> gallons;

    cout << "Foots = " << gallons / COEF << endl;

    return 0;

}