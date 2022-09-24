#include <iostream>
#include <cstdlib>
using namespace std;

class Sterlings {

private:
    int pounds;
    int shillings;
    int pence;

public:
    Sterlings() : pounds(0), shillings(0), pence(0) {}

    Sterlings(int pnds, int sh, int pn) : pounds(pnds), shillings(sh), pence(pn) {}

    Sterlings(double money){
        double oldPence = money * 100 * 2.4;
        pounds = oldPence / 240;
        oldPence -= pounds * 240;
        shillings = oldPence / 12;
        pence = static_cast<int>(oldPence) % 12;
    }

    void getSterlings(){
        char trash;
        cout << "Enter value in \"J9.19.11\" format: ";
        cin >> trash >> pounds >> trash >> shillings >> trash >> pence;
    }

    void putSterlings(){
        cout << 'J' << pounds << '.' << shillings << '.' << pence;
    }

    operator double() {
        return static_cast<double>(pence + shillings * 12 + pounds * 240);
    }

    Sterlings toSterlings(double money) const {

        int p = money / 240;
        money -= p * 240;
        int s = money / 12;
        int pn = static_cast<int>(money) % 12;

        return Sterlings(p, s, pn);

    }

    Sterlings operator + (Sterlings val2) const {
        return toSterlings(double(Sterlings(pounds, shillings, pence)) + double(val2));
    }

    Sterlings operator - (Sterlings val2) const {
        return toSterlings(double(Sterlings(pounds, shillings, pence)) - double(val2));
    }

    Sterlings operator * (double val) const {
        return toSterlings(val * double(Sterlings(pounds, shillings, pence)));
    }

    Sterlings operator / (Sterlings val2) const {
        double val2d = double(val2);
        if(val2d == 0.0){
            cout << "Can't be divided by zero.\n";
            exit(1);
        }
        return toSterlings(double(Sterlings(pounds, shillings, pence)) / val2d);
    }

    Sterlings operator / (double val) const {
        if(val == 0.0){
            cout << "Can't be divided by zero.\n";
            exit(1);
        }
        return toSterlings(double(Sterlings(pounds, shillings, pence)) / val);
    }

};


int main(void) {

    Sterlings val1, val2, val3;
    double val;
    char answer;

    do {

        cout << "First value\n"; val1.getSterlings();
        cout << "\nSecond value\n"; val2.getSterlings();
        cout << "\nEnter double value: "; cin >> val;

        val3 = val1 + val2;
        cout << "\nval1 + val2 = "; val3.putSterlings(); cout << endl;
        val3 = val1 - val2;
        cout << "\nval1 - val2 = "; val3.putSterlings(); cout << endl;
        val3 = val1 * val;
        cout << "\nval1 * val = "; val3.putSterlings(); cout << endl;
        val3 = val1 / val2;
        cout << "\nval1 / val2 = "; val3.putSterlings(); cout << endl;
        val3 = val1 / val;
        cout << "\nval1 / val = "; val3.putSterlings(); cout << endl;

        cout << "Do you want to continue (y / n): ";
        cin >> answer;

    } while(answer == 'y');


    return 0;

}
