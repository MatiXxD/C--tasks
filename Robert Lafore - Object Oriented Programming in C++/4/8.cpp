#include <iostream>
using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};

int main(void) {

    Fraction frac1, frac2;
    char trash;

    cout << "Enter first fraction (format a/b): ";
    cin >> frac1.numerator >> trash >> frac1.denominator;
    cout << "Enter second fraction (format a/b): ";
    cin >> frac2.numerator >> trash >> frac2.denominator;

    cout << "Result: " << frac1.numerator * frac2.denominator + frac1.denominator * frac2.numerator
        << '/' << frac1.denominator * frac2.denominator << endl;

    return 0;

}
