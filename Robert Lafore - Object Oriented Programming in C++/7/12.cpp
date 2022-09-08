#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class BMoney {

private:
	long double money;

public:
	BMoney() : money(0.0) {}

	void setMoney(string str) {
		money = mstold(str);
	}

	void madd(BMoney m1, BMoney m2) {
		money = m1.money + m2.money;
	}

	void putMoney() {
		cout << ldtoms(money);
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

	do {

		cout << "Enter first value ($1,234,567,890,123.99): ";
		cin >> val1; money1.setMoney(val1);
		cout << "Enter second value ($1,234,567,890,123.99): ";
		cin >> val2; money2.setMoney(val2);

		money3.madd(money1, money2);
		cout << "Sum of this values: ";
		money3.putMoney(); cout << endl;

		cout << "Do you want to continue (y / n): ";
		cin >> answer;

	} while (answer == 'y');

	return 0;

}
