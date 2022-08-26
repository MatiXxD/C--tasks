#include <iostream>
using namespace std;


struct Sterling {
    int pounds;
    int shillings;
    int pence;
};


Sterling getSterlings();
Sterling sumSterlings(const Sterling& val1, const Sterling& val2);
void displaySterlings(const Sterling& val);


int main(void) {

    Sterling val1, val2, sumVal;

    cout << "Enter first value\n";
    val1 = getSterlings();
    cout << "\nEnter second value\n";
    val2 = getSterlings();
    cout << endl;

    sumVal = sumSterlings(val1, val2);
    displaySterlings(val1);     cout << " + ";
    displaySterlings(val2);     cout << " = ";
    displaySterlings(sumVal);   cout << endl;

    return 0;

}


Sterling getSterlings() {

    Sterling newVal;

    cout << "Enter pounds: ";
    cin >> newVal.pounds;
    cout << "Enter shillings: ";
    cin >> newVal.shillings;
    cout << "Enter pence: ";
    cin >> newVal.pence;

    return newVal;

}

Sterling sumSterlings(const Sterling& val1, const Sterling& val2) {

    Sterling sumVal;

    sumVal.pounds = val1.pounds + val2.pounds;
    sumVal.shillings = val1.shillings + val2.shillings;
    sumVal.pence = val1.pence + val2.pence;
    if (sumVal.pence >= 12) {
        sumVal.shillings++;
        sumVal.pence -= 12;
    }
    if (sumVal.shillings >= 20) {
        sumVal.pounds++;
        sumVal.shillings -= 20;
    }

    return sumVal;

}

void displaySterlings(const Sterling& val) {

    cout << 'J' << val.pounds << '.' << val.shillings
        << '.' << val.pence;

}
