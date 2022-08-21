#include <iostream>

using namespace std;

int main() {

	int choice;
	float temperature;

	cout << "Type 1 to convert fahrenheit to celsius,"
		<< "\n     2 to convert celsius to fahrenheit: ";
	cin >> choice;

	if (choice == 1 || choice == 2) {
		cout << "Enter temperature: ";
		cin >> temperature;
		cout << "Converted temperature is: " << ((choice == 1) ?
			(temperature - 32.0f) / 9.0f * 5.0f :
			temperature * 9.0f / 5.0f + 32) << endl;
	}
	else {
		cout << "Wrong choice.\n";
	}

	return 0;

}
