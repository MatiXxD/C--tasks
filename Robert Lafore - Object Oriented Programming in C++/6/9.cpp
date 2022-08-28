#include <iostream>
using namespace std;

class Fraction {

private:
	int numerator;
	int denominator;

public:
	Fraction() : numerator(1), denominator(1) {}

	Fraction(int n, int d) : numerator(n), denominator(d) {}

	void getFraction() {
		char trash;
		cout << "Enter fraction in a/b format: ";
		cin >> numerator >> trash >> denominator;
		while (denominator == 0) {
			cout << "Denominator can't be equal to 0. Try again: ";
			cin >> numerator >> trash >> denominator;
		}
	}

	void display() const {
		cout << numerator << '/' << denominator;
	}

	void sum(const Fraction& frac1, const Fraction& frac2) {
		numerator = frac1.numerator * frac2.denominator + frac1.denominator * frac2.numerator;
		denominator = frac1.denominator * frac2.denominator;
	}

};


int main() {

	Fraction frac1, frac2, frac3;
	char answer;

	do {

		cout << "First fraction:\n";
		frac1.getFraction();
		cout << "Second fraction:\n";
		frac2.getFraction();

		frac3.sum(frac1, frac2);
		frac1.display(); cout << " + ";
		frac2.display(); cout << " = ";
		frac3.display(); cout << endl;

		cout << "\nDo you want to continue (y/n): ";
		cin >> answer;

	} while (answer == 'y');

	return 0;

}
