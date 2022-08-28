#include <iostream>
#include <iomanip>
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
		cout << setw(8) << numerator << '/' << denominator;
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

	int den;
	cout << "Enter denominator: ";
	cin >> den;

	cout << setw(8) << "";
	for (int numerator = 1; numerator < den; numerator++) {
		Fraction temp(numerator, den);
		temp.display();
	}
	cout << endl << setfill('.') << setw(14 * (den - 1)) << "";
	cout << setfill(' '); cout << endl;

	for (int i = 1; i < den; i++) {

		Fraction frac1(i, den);
		frac1.display();

		for (int j = 1; j < den; j++) {
			Fraction frac2(j, den), frac3;
			frac3.mlt(frac1, frac2);
			frac3.display();
		}
		cout << endl;

	}

	return 0;

}
