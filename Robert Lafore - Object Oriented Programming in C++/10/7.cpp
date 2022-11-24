#include <iostream>
#include <string>
using namespace std;

class Person {

protected:
    string name;
    double salary;

public:
    void setName() {
        cout << "Enter name: "; cin >> name;
    }
    void setSalary() {
        cout << "Enter salary: "; cin >> salary;
    }

    void printName() {
        cout << endl << name;
    }
    void printSalary() {
        cout << ' ' << salary;
    }

    string getName() {
        return name;
    }
    double getSalary() {
        return salary;
    }

};


void sortName(Person**, int);
void sortSal(Person**, int);
void printPer(Person**, int);


int main() {

    Person* persPtr[100];
    int n = 0;
    char choice;

    do {
        persPtr[n] = new Person;
        persPtr[n]->setName();
        persPtr[n]->setSalary();
        n++;
        cout << "Enter another (y/n)? ";
        cin >> choice;
    } while (choice == 'y');

    cout << "\nUnsorted list:";
    printPer(persPtr, n); cout << endl;

    sortName(persPtr, n);
    cout << "\nSorted by name list:";
    printPer(persPtr, n); cout << endl;

    sortSal(persPtr, n);
    cout << "\nSorted by name list:";
    printPer(persPtr, n); cout << endl;

    return 0;

}


void sortName(Person** p, int n) {

    int i, j;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if ((*(p + i))->getName() > (*(p + j))->getName()) {
                Person* temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }

}

void sortSal(Person** p, int n) {

    int i, j;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if ((*(p + i))->getSalary() < (*(p + j))->getSalary()) {
                Person* temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }

}

void printPer(Person** persons, int n) {

    for (int j = 0; j < n; j++) {
        persons[j]->printName();
        persons[j]->printSalary();
    }

}
