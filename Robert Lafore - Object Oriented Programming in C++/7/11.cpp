#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std;


class Money {

private:
	long double moneyAmount;
	string strMoney;

public:
	Money() : moneyAmount(0.0) {}

	void getMoney() {
		cout << "Enter money amount ($1,234,567,890,123.99): ";
		cin >> strMoney;
		this->mstold();
	}

	void printMoney() {
		cout << "Str: " << strMoney << endl;
		cout << "Long double value: " << setiosflags(ios::fixed) <<
			setprecision(2) << moneyAmount << endl;
	}

	void mstold();
	void ldtoms(long double val);

};

void Money::mstold() {

	char* end;
	string copy = strMoney;

	copy.erase(0, 1);							// Remove '$'
	int ind = copy.find(',');
	while (ind != string::npos) {				// Loop over all ','
		copy.erase(ind, 1);
		ind = copy.find(',');
	}

	moneyAmount = strtold(copy.c_str(), &end);

}

void Money::ldtoms(long double val) {

	moneyAmount = val;
	stringstream out;
	out << setprecision(2) << setiosflags(ios::fixed) << moneyAmount;
	out >> strMoney;

	int pos = strMoney.size() - 6;
	while (pos > 0) {
		strMoney.insert(pos, ",");
		pos -= 3;
	}
	strMoney.insert(0, "$");

	cout << strMoney;

}


int main() {

	Money money;
	long double val;
	char answer;

	do {

		cout << "Enter your value: ";
		cin >> val;
		cout << "String: "; money.ldtoms(val);

		cout << "\nDo you want to continue (y / n): ";
		cin >> answer;

	} while (answer == 'y');

	return 0;

}
