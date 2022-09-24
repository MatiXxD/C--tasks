#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class BMoney {

private:
	long double money;

public:
	BMoney() : money(0.0) {}
	BMoney(long double m) : money(m) {}

	void setMoney(string str) {
		money = mstold(str);
	}

	void putMoney() {
		cout << ldtoms(money);
	}

	BMoney operator + (BMoney m2) {
		return BMoney(money + m2.money);
	}

	BMoney operator - (BMoney m2) {
		return BMoney(money - m2.money);
	}

	BMoney operator * (double mlt) {
		return BMoney(money * mlt);
	}

	BMoney operator / (double div) {
		if (div == 0)
			exit(1);
		return BMoney(money / div);
	}

	long double mstold(string str);
	string ldtoms(long double val);

};

long double BMoney::mstold(string str) {

	stringstream stream;
	long double res;

	str.erase(0, 1);
	int pos = str.find(",");
	while (pos != string::npos) {
		str.erase(pos, 1);
		pos = str.find(",");
	}

	stream << str;
	stream >> res;
	return res;

}

string BMoney::ldtoms(long double val) {

	stringstream stream;
	string str;
	stream << setprecision(2) << setiosflags(ios::fixed) << val;
	stream >> str;

	int pos = str.size() - 6;
	while (pos > 0) {
		str.insert(pos, ",");
		pos -= 3;
	}
	str.insert(0, "$");

	return str;

}


int main() {

	char answer;
	BMoney money1, money2, money3;
	string val1, val2;
	double f;

	do {

		cout << "Enter first value ($1,234,567,890,123.99): ";
		cin >> val1; money1.setMoney(val1);
		cout << "Enter second value ($1,234,567,890,123.99): ";
		cin >> val2; money2.setMoney(val2);
		cout << "Enter float value: ";
		cin >> f;

		money3 = money1 + money2;
		cout << "m1+m2: "; money3.putMoney(); cout << endl;
		money3 = money1 - money2;
		cout << "m1-m2: "; money3.putMoney(); cout << endl;
		money3 = money1 * f;
		cout << "m1*f: "; money3.putMoney(); cout << endl;
		money3 = money1 / f;
		cout << "m1/f: "; money3.putMoney(); cout << endl;

		cout << "Do you want to continue (y / n): ";
		cin >> answer;

	} while (answer == 'y');

	return 0;

}
