#include <iostream>
using namespace std;
const int LEN = 80;

class employee {

private:
    char name[LEN];
    unsigned long number;

public:
    void getdata() {
        cout << "\n   Enter last name: "; cin >> name;
        cout << "   Enter number: ";      cin >> number;
    }

    void putdata() const {
        cout << "\n   Name: " << name;
        cout << "\n   Number: " << number << endl;
    }

};

class manager : public employee {

private:
    char title[LEN];
    double dues;

public:
    void getdata() {
        employee::getdata();
        cout << "   Enter title: ";          cin >> title;
        cout << "   Enter golf club dues: "; cin >> dues;
    }

    void putdata() const {
        employee::putdata();
        cout << "\n   Title: " << title;
        cout << "\n   Golf club dues: " << dues << endl;
    }

};

class scientist : public employee {

private:
    int pubs;

public:
    void getdata() {
        employee::getdata();
        cout << "   Enter number of pubs: "; cin >> pubs;
    }

    void putdata() const {
        employee::putdata();
        cout << "\n   Number of publications: " << pubs << endl;
    }

};

class laborer : public employee
{

};

class Compensation {

private:
    double compensation;
    string period;

    void toLower() {
        for (int i = 0; i < period.length(); i++)
            period[i] = tolower(period[i]);
    }

public:
    void getdata() {
        cout << "Enter compensation: "; cin >> compensation;
        cout << "Enter period: "; cin >> period; toLower();
        if (period.compare("hourly") && period.compare("weekly") &&
            period.compare("monthly")) {
            cout << "Wrong input. Use monthly as period.\n";
            period = "monthly";
        }
    }

    void putdata() {
        cout << "Compensation: " << compensation << endl;
        cout << "Period: " << period << endl;
    }

};

class Manager2 : private manager, private Compensation {

public:
    void getdata() {
        manager::getdata();
        Compensation::getdata();
    }

    void putdata() {
        manager::putdata();
        Compensation::putdata();
    }

};

class Scientist2 : private scientist, private Compensation {

public:
    void getdata() {
        scientist::getdata();
        Compensation::getdata();
    }

    void putdata() {
        scientist::putdata();
        Compensation::putdata();
    }

};

class Laborer2 : private laborer, private Compensation {

public:
    void getdata() {
        laborer::getdata();
        Compensation::getdata();
    }

    void putdata() {
        laborer::putdata();
        Compensation::putdata();
    }

};


int main() {

    Manager2 m1, m2;
    Scientist2 s1;
    Laborer2 l1;

    cout << endl;
    cout << "\nEnter data for manager 1";
    m1.getdata();

    cout << "\nEnter data for manager 2";
    m2.getdata();

    cout << "\nEnter data for scientist 1";
    s1.getdata();

    cout << "\nEnter data for laborer 1";
    l1.getdata();

    cout << "\nData on manager 1";
    m1.putdata();

    cout << "\nData on manager 2";
    m2.putdata();

    cout << "\nData on scientist 1";
    s1.putdata();

    cout << "\nData on laborer 1";
    l1.putdata();
    cout << endl;

    return 0;
    
}
