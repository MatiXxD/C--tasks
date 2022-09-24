#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;


class BMoney {

private:
    long double money;

public:
    BMoney() : money(0.0) {}

    BMoney(long double m) : money(m) {}

    void setMoney(string str) {
        money = mstold(str);
    }

    void inputMoney() {
        cout << "Enter money: ";
        cin >> money;
    }

    long double getMoney() {
        return money;
    }

    void putMoney() {
        cout << ldtoms(money);
    }

    BMoney operator + (BMoney m2) {
        return BMoney(money + m2.money);
    }

    BMoney operator - (BMoney m2) {
        return BMoney(money - m2.money);
    }

    BMoney operator * (double mlt) {
        return BMoney(money * mlt);
    }

    BMoney operator / (double div) {
        if (div == 0)
            exit(1);
        return BMoney(money / div);
    }

    long double mstold(string str);
    string ldtoms(long double val);

};

long double BMoney::mstold(string str) {

    stringstream stream;
    long double res;

    str.erase(0, 1);
    int pos = str.find(",");
    while (pos != string::npos) {
        str.erase(pos, 1);
        pos = str.find(",");
    }

    stream << str;
    stream >> res;
    return res;

}

string BMoney::ldtoms(long double val) {

    stringstream stream;
    string str;
    stream << setprecision(2) << setiosflags(ios::fixed) << val;
    stream >> str;

    int pos = str.size() - 6;
    while (pos > 0) {
        str.insert(pos, ",");
        pos -= 3;
    }
    str.insert(0, "$");

    return str;

}


class Sterlings {

private:
    int pounds;
    int shillings;
    int pence;

public:
    Sterlings() : pounds(0), shillings(0), pence(0) {}

    Sterlings(int pnds, int sh, int pn) : pounds(pnds), shillings(sh), pence(pn) {}

    Sterlings(double money) {
        double oldPence = money * 100 * 2.4;
        pounds = oldPence / 240;
        oldPence -= pounds * 240;
        shillings = oldPence / 12;
        pence = static_cast<int>(oldPence) % 12;
    }

    Sterlings(BMoney bmoney) {
        long double oldPence = bmoney.getMoney() / 50 * 240;
        pounds = oldPence / 240;
        oldPence -= pounds * 240;
        shillings = oldPence / 12;
        pence = static_cast<int>(oldPence) % 12;
    }

    void getSterlings() {
        char trash;
        cout << "Enter value in \"J9.19.11\" format: ";
        cin >> trash >> pounds >> trash >> shillings >> trash >> pence;
    }

    void putSterlings() {
        cout << 'J' << pounds << '.' << shillings << '.' << pence;
    }

    operator double() {
        return static_cast<double>(pence + shillings * 12 + pounds * 240);
    }

    operator BMoney() {
        return BMoney(double(Sterlings(pounds, shillings, pence)) * 50 / 240);
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
        if (val2d == 0.0) {
            cout << "Can't be divided by zero.\n";
            exit(1);
        }
        return toSterlings(double(Sterlings(pounds, shillings, pence)) / val2d);
    }

    Sterlings operator / (double val) const {
        if (val == 0.0) {
            cout << "Can't be divided by zero.\n";
            exit(1);
        }
        return toSterlings(double(Sterlings(pounds, shillings, pence)) / val);
    }

};


int main() {

    Sterlings s1, s2, s3;
    BMoney bm1, bm2, bm3;

    cout << "Enter two Sterlings values\n";
    s1.getSterlings(); s2.getSterlings();
    bm3 = s1 + s2;
    cout << "Sterlings1 + Sterlings2 = "; bm3.putMoney();

    cout << "\nEnter two BMoney values\n";
    bm1.inputMoney(); bm2.inputMoney();
    s3 = bm1 + bm2;
    cout << "BMoney1 + BMoney2 = "; s3.putSterlings();

    return 0;

}
