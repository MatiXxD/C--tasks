#include <iostream>

using namespace std;

int main(void){

    float sum;

    cout << "Enter sum in $: ";
    cin >> sum;

    cout << "GBP = " << sum / 1.487F << endl
        << "Franc = " << sum / 0.172F << endl
        << "Deutsche Mark = " << sum / 0.584F << endl
        << "Yen = " << sum / 0.00955 << endl; 

    return 0;

}