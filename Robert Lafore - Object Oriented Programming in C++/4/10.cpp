#include <iostream>
using namespace std;


struct Sterling {
    int pounds;
    int shillings;
    int pence;
};


int main(void) {

    Sterling oldFormat;
    int oldPence;
    double newFormat;

    cout << "Enter your balance in new format: ";
    cin >> newFormat;
    oldPence = newFormat * 100 * 2.4;

    oldFormat.pounds = oldPence / 240;
    oldPence -= oldFormat.pounds * 240;
    oldFormat.shillings = oldPence / 12;
    oldFormat.pence = oldPence % 12;

    cout << "Your balance in old format: " << 'J' << oldFormat.pounds << '.'
        << oldFormat.shillings << '.' << oldFormat.pence << endl;

    return 0;

}
