#include <iostream>

using namespace std;

int main() {

	int chairs, guests;
	cout << "Enter chairs number: ";
	cin >> chairs;
	cout << "Enter guests number: ";
	cin >> guests;

	if (guests < chairs || guests < 1 || chairs < 1) {
		cout << "Wrong input.\n";
		return 1;
	}

	unsigned long variants = 1;
	for (int chair = 0; chair < chairs; chair++)
		variants *= guests--;
	cout << "There are " << variants << " variants\n";

	return 0;

}
