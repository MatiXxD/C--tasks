#include <iostream>

using namespace std;

int main(void){

    float celsius;

    cout << "Enter temperature in celsius: ";
    cin >> celsius;
    cout << "Temperature in fahrenheit: " << 32 + celsius * (9.F/5.F) << endl;

    return 0;

}