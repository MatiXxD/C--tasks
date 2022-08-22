#include <iostream>
using namespace std;

struct Fraction {
	int numerator;
	int denominator;
};

int main() {

	Fraction frac1, frac2, frac3;
	char answer = 'y';
	char action, trash;

	while (answer == 'y') {

		cout << "Enter what you want to do (example: a/b + c/d): ";
		cin >> frac1.numerator >> trash >> frac1.denominator
			>> action >> frac2.numerator >> trash >> frac2.denominator;

		if (frac1.denominator == 0 || frac2.denominator == 0) {
			cout << "Can't divide by zero.\n";
			continue;
		}
		else if (action != '+' && action != '-' && action != '*' && action != '/') {
			cout << "Wrong operation.\n";
			continue;
		}

		switch (action) {
		case '+':
			frac3.numerator = frac1.numerator * frac2.denominator + frac1.denominator * frac2.numerator;
			frac3.denominator = frac1.denominator * frac2.denominator;
			break;
		case '-':
			frac3.numerator = frac1.numerator * frac2.denominator - frac1.denominator * frac2.numerator;
			frac3.denominator = frac1.denominator * frac2.denominator;
			break;
		case '*':
			frac3.numerator = frac1.numerator * frac2.numerator;
			frac3.denominator = frac1.denominator * frac2.denominator;
			break;
		case '/':
			if (frac2.numerator == 0) {
				cout << "Can't divide by zero.\n";
				continue;
			}
			frac3.numerator = frac1.numerator * frac2.denominator;
			frac3.denominator = frac2.numerator * frac1.denominator;
			break;
		}

		cout << frac1.numerator << '/' << frac1.denominator << ' ' << action
			<< ' ' << frac2.numerator << '/' << frac2.denominator
			<< " = " << frac3.numerator << '/' << frac3.denominator << endl;
		cout << "Do another (Enter 'y' or 'n')? ";
		cin >> answer;

	}

	return 0;

}
