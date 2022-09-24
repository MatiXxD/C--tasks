#include <iostream>
#include <limits>
using namespace std;

class Int {

private:
	int val;

public:
	Int() : val(0) { }

	Int(int num) : val(num) { }

	void displayVal() const {
		cout << val;
	}

	Int checkValue(long double temp) const{
		if (temp >= INT_MAX) {
			cout << "Out of range.\n";
			return Int(INT_MAX);
		}
		else if (temp <= INT_MIN) {
			cout << "Out of range.\n";
			return Int(INT_MIN);
		}
		else {
			return Int(static_cast<int>(temp));
		}
	}

	Int operator + (Int i2) const {
		long double temp = val + i2.val;
		return checkValue(temp);
	}

	Int operator - (Int i2) const {
		long double temp = val - i2.val;
		return checkValue(temp);
	}

	Int operator * (Int i2) const {
		long double temp = val * i2.val;
		return checkValue(temp);
	}

	Int operator / (Int i2) const {
		if (i2.val == 0) {
			cout << "Can't divide by zero.";
			return Int(0);
		}
		long double temp = val / i2.val;
		return checkValue(temp);
	}

};

int main() {

	Int num1(342), num2(21);
	Int num3;

	num1.displayVal(); cout << endl;
	num2.displayVal(); cout << endl;

	num3 = num1 + num2;
	cout << "+: "; num3.displayVal(); cout << endl;

	num3 = num1 - num2;
	cout << "-: "; num3.displayVal(); cout << endl;

	num3 = num1 * num2;
	cout << "*: "; num3.displayVal(); cout << endl;

	num3 = num1 / num2;
	cout << "/: "; num3.displayVal(); cout << endl;

	return 0;

}
