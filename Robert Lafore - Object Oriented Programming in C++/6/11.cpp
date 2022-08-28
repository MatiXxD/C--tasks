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

	void lowTerms();

	void sum(const Fraction& frac1, const Fraction& frac2) {
		numerator = frac1.numerator * frac2.denominator + frac1.denominator * frac2.numerator;
		denominator = frac1.denominator * frac2.denominator;
		this->lowTerms();
	}

	void sub(const Fraction& frac1, const Fraction& frac2) {
		numerator = frac1.numerator * frac2.denominator - frac1.denominator * frac2.numerator;
		denominator = frac1.denominator * frac2.denominator;
		this->lowTerms();
	}

	void mlt(const Fraction& frac1, const Fraction& frac2) {
		numerator = frac1.numerator * frac2.numerator;
		denominator = frac1.denominator * frac2.denominator;
		this->lowTerms();
	}

	void div(const Fraction& frac1, const Fraction& frac2) {
		if (frac2.numerator == 0) {
			cout << "Illegal fraction : division by 0";
			exit(1);
		}
		numerator = frac1.numerator * frac2.denominator;
		denominator = frac2.numerator * frac1.denominator;
		this->lowTerms();
	}

};

void Fraction::lowTerms() {

	int tnum, tden, temp, gcd;
	tnum = abs(numerator);
	tden = abs(denominator);
	if (tden == 0) {
		cout << "Illegal fraction : division by 0";
		exit(1);
	}
	else if (tnum == 0) {
		numerator = 0; denominator = 1; return;
	}

	while (tnum != 0){
		if (tnum < tden) {
			temp = tnum; tnum = tden; tden = temp;
		}
		tnum = tnum - tden;
	}
	gcd = tden;
	numerator = numerator / gcd;
	denominator = denominator / gcd;

}


int main() {

	Fraction frac1, frac2, frac3;
	char operation, answer;

	do {

		cout << "First fraction\n";
		frac1.getFraction();
		cout << "Second fraction\n";
		frac2.getFraction();
		cout << "Now enter operation: ";
		cin >> operation;
		if (operation != '+' && operation != '-' && operation != '*' && operation != '/')
			operation = '+';
		switch(operation) {
		case '+':	frac3.sum(frac1, frac2);	break;
		case '-':	frac3.sub(frac1, frac2);	break;
		case '*':	frac3.mlt(frac1, frac2);	break;
		case '/':	frac3.div(frac1, frac2);	break;
		}

		frac1.display(); cout << ' ' << operation << ' ';
		frac2.display(); cout << " = ";
		frac3.display(); cout << endl;

		cout << "\nDo you want to continue (y/n): ";
		cin >> answer;

	} while (answer == 'y');


	return 0;

}
