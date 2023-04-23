#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class BMoney {

private:
	long double money;

	bool goodString(string str);

public:
	BMoney() : money(0.0) {}
	BMoney(long double m) : money(m) {}

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

	friend long double operator * (double, BMoney&);
	friend long double operator / (double, BMoney&);
	friend istream& operator >> (istream&, BMoney&);
	friend ostream& operator << (ostream&, BMoney&);

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

long double operator * (double dmoney, BMoney& bmoney) {

	return dmoney * bmoney.money;

}

long double operator / (double dmoney, BMoney& bmoney) {

	return dmoney / bmoney.money;

}

bool BMoney::goodString(string str) {

	int pos = str.find(",");
	if (str[0] != '$' || pos > 4) return false;

	int count = 0;
	for (int i = pos + 1; i < str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			count++;
		}
		else if (str[i] == ',') {
			if (count != 3) return false;
			count = 0;
		}
		else if (str[i] == '.') {
			if (count != 3) return false;
			break;
		}
		else {
			return false;
		}
	}

	return true;

}

istream& operator>>(istream& s, BMoney& bm) {

	string temp;
	s >> temp;
	while (!bm.goodString(temp) || !s.good()) {
		s.clear(); s.ignore(1024, '\n');
		cout << "Wrong string. Enter again: ";
		s >> temp;
	}

	bm.money = bm.mstold(temp);

	return s;

}

ostream& operator << (ostream& s, BMoney& bm) {

	cout << bm.ldtoms(bm.money);

	return s;

}


int main() {

	char answer;
	BMoney money1, money2, money3;
	string val1, val2;
	double f;

	do {

		cout << "Enter two money values ($1,234,567,890,123.99) and one float: ";
		cin >> money1 >> money2 >> f;

		money3 = money1 + money2;
		cout << "m1+m2: "; cout << money3 << endl;
		money3 = money1 - money2;
		cout << "m1-m2: "; cout << money3 << endl;
		money3 = money1 * f;
		cout << "m1*f: "; cout << money3 << endl;
		money3 = money1 / f;
		cout << "m1/f: "; cout << money3 << endl;
		money3 = f * money1;
		cout << "f*m1: "; cout << money3 << endl;
		money3 = f / money1;
		cout << "f/m1: "; cout << money3 << endl;

		cout << "Do you want to continue (y / n): ";
		cin >> answer;

	} while (answer == 'y');

	return 0;

}
