#include <iostream>

using namespace std;

int main() {

	int pounds, shillings, pence, temp;
	char answer, trash;

	do {

		cout << "Enter first amount: ";
		cin >> trash >> pounds >> trash >> shillings >> trash >> pence;
		cout << "Enter second amount: ";

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


		cout << "Total is J" << pounds << '.' << shillings
			<< '.' << pence << endl;
		cout << "Do you wish to continue (y/n)? ";
		cin >> answer;

	} while (answer == 'y');

	return 0;

}
