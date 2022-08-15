#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    cout << setiosflags(ios::left);
    cout << setw(12) << "Lastname" << setw(12) << "Firstname"
        << setw(18) << "Address" << setw(18) << "Сity" << endl;
    
    cout << setfill('-');
    cout << setw(12+12+18+18) << "" << endl;

    cout << setfill(' ');
    cout << setw(12) << "Petrov" << setw(12) << "Vasiliy"
        << setw(18) << "Klenovaia 16" << setw(18) << "Saint Petersburg" << endl;
    cout << setw(12) << "Ivanov" << setw(12) << "Sergey"
        << setw(18) << "Osinovaia 3" << setw(18) << "Nakhodka" << endl;
    cout << setw(12) << "Sidorov" << setw(12) << "Ivan"
        << setw(18) << "Berezovaia 21" << setw(18) << "Kaliningrad" << endl;

    return 0;

}