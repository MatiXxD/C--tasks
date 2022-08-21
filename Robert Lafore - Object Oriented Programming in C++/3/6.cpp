#include <iostream>

using namespace std;

int main() {

	char answer;
	unsigned int numb, fact;

	cout << "Enter a number: ";
	cin >> numb;
	while (numb != 0) {

		fact = 1;
		for (int j = numb; j > 0; j--)
			fact *= j;
		cout << "Factorial is " << fact << endl;

		cout << "Enter a number: ";
		cin >> numb;

	}

	return 0;

}
