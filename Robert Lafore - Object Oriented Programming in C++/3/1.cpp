#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int num, currentNum;

	cout << "Enter number: ";
	cin >> num;
	currentNum = num;

	for (int i = 1; i <= 200; i++) {
		cout << setw(5) << currentNum;
		currentNum += num;
		if (!(i % 10))
			cout << endl;
	}

	return 0;

}
