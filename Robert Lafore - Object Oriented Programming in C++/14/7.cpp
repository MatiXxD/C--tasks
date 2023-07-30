#include <iostream>
using namespace std;

template <class type>
class Fraction {

private:
	type numerator;
	type denominator;

public:
	Fraction() : numerator(1), denominator(1) {}

	Fraction(type n, type d) : numerator(n), denominator(d) {}

	void display() const {
		cout << static_cast<int>(numerator) << '/' << static_cast<int>(denominator);
	}

	Fraction operator + (Fraction frac2) const {
		Fraction frac;
		frac.numerator = numerator * frac2.denominator + denominator * frac2.numerator;
		frac.denominator = denominator * frac2.denominator;
		return frac.lowTerms();

	}

	Fraction operator - (Fraction frac2) const {
		Fraction frac;
		frac.numerator = numerator * frac2.denominator - denominator * frac2.numerator;
		frac.denominator = denominator * frac2.denominator;
		return frac.lowTerms();
	}

	Fraction operator * (Fraction frac2) const {
		Fraction frac;
		frac.numerator = numerator * frac2.numerator;
		frac.denominator = denominator * frac2.denominator;
		return frac.lowTerms();
	}

	Fraction operator / (Fraction frac2) const {
		if (frac2.numerator == 0) {
			cout << "Illegal fraction : division by 0";
			exit(1);
		}
		Fraction frac;
		frac.numerator = numerator * frac2.denominator;
		frac.denominator = frac2.numerator * denominator;
		return frac.lowTerms();
	}

	bool operator == (Fraction frac) const {
		return (numerator == frac.numerator) && (denominator == frac.denominator);
	}

	bool operator != (Fraction frac) const {
		return !((numerator == frac.numerator) && (denominator == frac.denominator));
	}

	void getFraction();
	Fraction lowTerms() const;

};

template <class type>
void Fraction<type>::getFraction() {

	int temp1, temp2;
	char trash;

	cout << "Enter fraction in a/b format: ";
	cin >> temp1 >> trash >> temp2;
	while (temp2 == 0) {
		cout << "Denominator can't be equal to 0. Try again: ";
		cin >> temp1 >> trash >> temp2;
	}

	numerator = temp1; denominator = temp2;

}

template <class type>
Fraction<type> Fraction<type>::lowTerms() const {

	type tnum, tden, temp, gcd;
	tnum = abs(numerator);
	tden = abs(denominator);
	if (tden == 0) {
		cout << "Illegal fraction : division by 0";
		exit(1);
	}
	else if (tnum == 0) {
		return Fraction(0, 1);
	}

	while (tnum != 0) {
		if (tnum < tden) {
			temp = tnum; tnum = tden; tden = temp;
		}
		tnum = tnum - tden;
	}
	gcd = tden;

	return Fraction(numerator / gcd, denominator / gcd);

}


int main() {

	Fraction<char> frac1, frac2, frac3;
	char operation;

	cout << "First fraction (0/1 to stop for both fractions)\n";
	frac1.getFraction();
	cout << "Second fraction\n";
	frac2.getFraction();

	while (frac1 != Fraction<char>(0, 1) && frac2 != Fraction<char>(0, 1)) {

		cout << "Now enter operation: ";
		cin >> operation;
		if (operation != '+' && operation != '-' && operation != '*' && operation != '/')
			operation = '+';
		switch (operation) {
		case '+':	frac3 = frac1 + frac2;	break;
		case '-':	frac3 = frac1 - frac2;	break;
		case '*':	frac3 = frac1 * frac2;	break;
		case '/':	frac3 = frac1 / frac2;	break;
		}

		frac1.display(); cout << ' ' << operation << ' ';
		frac2.display(); cout << " = ";
		frac3.display(); cout << endl;

		cout << "First fraction (0/1 to stop for both fractions)\n";
		frac1.getFraction();
		cout << "Second fraction\n";
		frac2.getFraction();

	}


	return 0;

}
