#include <iostream>

using namespace std;

int main() {

	char answer = 'y';
	char action;
	float num1, num2, res;

	while (answer == 'y') {

		cout << "Enter first number, operator, second number: ";
		cin >> num1 >> action >> num2;
		if (num2 == 0 && action == '/') {
			cout << "Can't divide by zero.\n";
			continue;
		}
		else if (action != '+' && action != '-' && action != '*' && action != '/') {
			cout << "Wrong operation.\n";
			continue;
		}

		switch (action) {
		case '+':	res = num1 + num2;	break;
		case '-':	res = num1 - num2;	break;
		case '*':	res = num1 * num2;	break;
		case '/':	res = num1 / num2;	break;
		}

		cout << "Result: " << res << endl;
		cout << "Do another (Enter 'y' or 'n')? ";
		cin >> answer;

	}

	return 0;

}
