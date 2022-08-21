#include <iostream>
#include <conio.h>

using namespace std;

int main() {

	bool isPositive;
	char ch;

	cout << "Enter number: ";
	ch = _getche();
	isPositive = !(ch == '-');

	long number = 0;
	if (isPositive) {
		while (ch != '\r') {
			number = number * 10 + (ch - '0');
			ch = _getche();
		}
	}
	else {
		ch = _getche();
		while (ch != '\r') {
			number = number * 10 - (ch - '0');
			ch = _getche();
		}
	}

	cout << "Your number is: " << number << endl;

	return 0;

}
