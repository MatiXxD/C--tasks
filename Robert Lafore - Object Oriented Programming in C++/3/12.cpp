#include <iostream>

using namespace std;

int main() {

	char answer = 'y';
	char action, trash;
	int a, b, c, d;
	int numerator, denominator;

	while (answer == 'y') {

		cout << "Enter what you want to do (example: a/b + c/d): ";
		cin >> a >> trash >> b >> action >> c >> trash >> d;

		if (b == 0 || d == 0) {
			cout << "Can't divide by zero.\n";
			continue;
		}
		else if (action != '+' && action != '-' && action != '*' && action != '/') {
			cout << "Wrong operation.\n";
			continue;
		}

		switch (action) {
		case '+':
			numerator = a * d + b * c;
			denominator = b * d;
			break;
		case '-':
			numerator = a * d - b * c;
			denominator = b * d;
			break;
		case '*':
			numerator = a * c;
			denominator = b * d;
			break;
		case '/':
			if (c == 0) {
				cout << "Can't divide by zero.\n";
				continue;
			}
			numerator = a * d;
			denominator = b * c;
			break;
		}

		cout << a << '/' << b << ' ' << action << ' ' << c << '/' << d
			<< " = " << numerator << '/' << denominator << endl;
		cout << "Do another (Enter 'y' or 'n')? ";
		cin >> answer;

	}

	return 0;

}
