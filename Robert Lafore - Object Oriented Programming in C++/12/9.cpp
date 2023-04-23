#include <iostream>
using namespace std;


///////////////////////////////////////////////////////////////////////////////////////////////////////////


class Fraction {

private:
	int numerator;
	int denominator;

public:
	Fraction() : numerator(1), denominator(1) {}
	Fraction(int n, int d) : numerator(n), denominator(d) {}
	bool bad() { return denominator == 0; }

	void display() const {
		cout << numerator << '/' << denominator;
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


	Fraction lowTerms() const;

	friend istream& operator >> (istream& s, Fraction& frac);
	friend ostream& operator << (ostream& s, Fraction& frac);

};

Fraction Fraction::lowTerms() const {

	int tnum, tden, temp, gcd;
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////

istream& operator >> (istream& s, Fraction& frac) {

	char trash;
	s >> frac.numerator >> trash >> frac.denominator;

	return s;

}

ostream& operator << (ostream& s, Fraction& frac) {

	s << frac.numerator << '/' << frac.denominator;

	return s;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////


int main() {

	Fraction frac1, frac2, frac3;
	char operation;

	cout << "Fraction has the form a/b.\n"
		"If you want to stop make two fraction equal to \"0/1\"\n";
	cout << "Enter two fraction in format (frac operation frac): ";
	cin >> frac1 >> operation >> frac2;
	while (frac1 != Fraction(0, 1) && frac2 != Fraction(0, 1)) {

		if (frac1.bad() || frac2.bad()) {
			cout << "Denominator can't be 0.\n";
		}
		else {

			switch (operation) {
			case '+':	frac3 = frac1 + frac2;	break;
			case '-':	frac3 = frac1 - frac2;	break;
			case '*':	frac3 = frac1 * frac2;	break;
			case '/':	frac3 = frac1 / frac2;	break;
			default: cout << "Wrong operation.\n"; break;
			}

			cout << frac1 << ' ' << operation << ' ' << frac2 << " = " << frac3;
		}

		cout << "\nEnter next example: ";
		cin >> frac1 >> operation >> frac2;

	}

	return 0;

}
