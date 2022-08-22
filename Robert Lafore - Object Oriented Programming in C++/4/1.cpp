#include <iostream>
using namespace std;

struct Phone {
	int areaCode;
	int exchange;
	int number;
};

int main() {

	Phone phone1 = {212, 767, 8900};
	Phone phone2;

	cout << "Enter your area code, exchange, and number: ";
	cin >> phone2.areaCode >> phone2.exchange >> phone2.number;

	cout << "My number is " << '(' << phone1.areaCode << ") " << phone1.exchange
		<< '-' << phone1.number << endl;
	cout << "Your number is " << '(' << phone2.areaCode << ") " << phone2.exchange
		<< '-' << phone2.number << endl;

	return 0;

}
