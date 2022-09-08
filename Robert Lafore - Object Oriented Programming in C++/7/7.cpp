#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
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



int main() {

	Money money;

	money.getMoney();
	money.printMoney();

	return 0;

}
