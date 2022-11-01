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
		cout << numerator << '/' << denominator;
	}

	void setFrac(int n, int d) {
		numerator = n;
		denominator = d;
	}

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

	int getNm() const { return numerator; }
	int getDnm() const { return denominator; }
	void lowTerms();

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

	while (tnum != 0) {
		if (tnum < tden) {
			temp = tnum; tnum = tden; tden = temp;
		}
		tnum = tnum - tden;
	}
	gcd = tden;
	numerator = numerator / gcd;
	denominator = denominator / gcd;

}

class Sterlings {

protected:
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

class SterFrac : private Sterlings {

private:
	Fraction eighths;

public:
	SterFrac() : eighths(), Sterlings() {

	}

	SterFrac(int pnds, int sh, int pn, int e) : eighths(e, 8), Sterlings(pnds, sh, pn) {

	}

	void getSterlings() {
		char trash;
		int n;
		cout << "Enter value in \"J9.19.11-3/8\" format: ";
		cin >> trash >> pounds >> trash >> shillings >> trash >> pence
			>> trash >> n >> trash >> trash;
		eighths.setFrac(n, 8);
	}

	void putSterlings() {
		cout << 'J' << pounds << '.' << shillings << '.' << pence;
		if (eighths.getNm() != 0) {
			cout << '-';
			eighths.display();
		}
	}

	operator double() {
		return ((pence + static_cast<double>(eighths.getNm())) + shillings * 12 + pounds * 240);
	}

	SterFrac toSterlings(double money) const {

		int p = money / 240;
		money -= p * 240;
		int s = money / 12;
		money -= s * 12;
		int pn = static_cast<int>(money);
		int e = 10 * (money - pn);

		return SterFrac(p, s, pn, e);

	}

	SterFrac operator + (SterFrac val2) const {

		int pnds = 0, sh = 0, pn = 0, e = 0;

		e = eighths.getNm() + val2.eighths.getNm();
		if (e >= 8) {
			e -= 8;
			pn++;
		}

		pn += pence + val2.pence;
		if (pence >= 12) {
			pn -= 12;
			sh++;
		}

		sh += shillings + val2.shillings;
		if (sh >= 20) {
			sh -= 20;
			pnds++;
		}

		pnds += pounds + val2.pounds;

		return SterFrac(pnds, sh, pn, e);

	}

	SterFrac operator - (SterFrac val2) const {

		int pnds = 0, sh = 0, pn = 0, e = 0;

		e = eighths.getNm() - val2.eighths.getNm();
		if (e < 0) {
			e += 8;
			pn--;
		}

		pn += pence - val2.pence;
		if (pence < 0) {
			pn += 12;
			sh--;
		}

		sh += shillings - val2.shillings;
		if (sh < 0) {
			sh += 20;
			pnds--;
		}

		pnds += pounds - val2.pounds;

		return SterFrac(pnds, sh, pn, e);

	}

	SterFrac operator * (double val) const {

		double sum = val * double(SterFrac(pounds, shillings, pence, eighths.getNm()));
		return toSterlings(sum);

	}

	SterFrac operator / (SterFrac val2) const {

		double sum1 = double(SterFrac(pounds, shillings, pence, eighths.getNm()));
		double sum2 = double(val2);
		if (sum2 == 0) {
			cout << "Can't be divided by zero.\n";
			return SterFrac();
		}

		return toSterlings(sum1 / sum2);

	}

};



int main() {

	SterFrac val1, val2, val3;
	double val;
	char answer;

	do {

		cout << "First value\n"; val1.getSterlings();
		cout << "\nSecond value\n"; val2.getSterlings();
		cout << "\nEnter double value: "; cin >> val;

		val3 = val1 + val2;
		cout << "\nval1 + val2 = "; val3.putSterlings(); cout << endl;
		val3 = val1 - val2;
		cout << "\nval1 - val2 = "; val3.putSterlings(); cout << endl;
		val3 = val1 * val;
		cout << "\nval1 * val = "; val3.putSterlings(); cout << endl;
		val3 = val1 / val2;
		cout << "\nval1 / val2 = "; val3.putSterlings(); cout << endl;

		cout << "Do you want to continue (y / n): ";
		cin >> answer;

	} while (answer == 'y');

}
