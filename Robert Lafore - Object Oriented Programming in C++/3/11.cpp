#include <iostream>

using namespace std;

int main() {

	char action, trash;
	char answer = 'y';
	int pounds, shillings, pence, temp;
	float coef;

	while (answer == 'y') {

		cout << "Enter first value: ";
		cin >> trash >> pounds >> trash >> shillings >> trash >> pence;
		cout << "Enter operation: ";
		cin >> action;

		if (action != '+' && action != '-' && action != '*' && action != '/') {
			cout << "Wrong operation.\n";
			continue;
		}
		else if (action == '+' || action == '-') {
			cout << "Enter second value: ";
			if (action == '+') {
				cin >> trash >> temp >> trash;
				pounds += temp;
				cin >> temp >> trash;
				shillings += temp;
				if (shillings >= 20) {
					pounds++;
					shillings -= 20;
				}
				cin >> temp;
				pence += temp;
				if (pence >= 12) {
					shillings++;
					pence -= 12;
				}
			}
			else {
				cin >> trash >> temp >> trash;
				pounds -= temp;
				cin >> temp >> trash;
				shillings -= temp;
				if (shillings < 0) {
					pounds--;
					shillings += 20;
				}
				cin >> temp;
				pence -= temp;
				if (pence < 0) {
					shillings--;
					pence += 12;
				}
			}
		}
		else {
			cout << "Enter number: ";
			cin >> coef;
			temp = 20 * 12 * pounds + 12 * shillings + pence;
			if (action == '*') {
				temp *= coef;
			}
			else {
				if (coef != 0) {
					temp /= coef;
				}
				else {
					cout << "Can't divide by zero.\n";
					continue;
				}
			}
			pounds = temp / (20 * 12);
			temp -= pounds * 20 * 12;
			shillings = temp / 12;
			temp -= shillings * 12;
			pence = temp;
		}

		cout << "Result: " << 'J' << pounds << '.' << shillings << '.' << pence << endl;
		cout << "Do another (Enter 'y' or 'n')? ";
		cin >> answer;

	}

	return 0;

}
