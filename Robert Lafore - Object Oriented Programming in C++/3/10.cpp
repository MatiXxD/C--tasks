#include <iostream>

using namespace std;

int main() {

	double balance, rate, finalAmount;
	cout << "Enter your deposit: ";
	cin >> balance;
	cout << "Enter interest rate (percent per year): ";
	cin >> rate;
	rate /= 100;
	cout << "Enter final amount: ";
	cin >> finalAmount;

	int year;
	for (year = 0; balance < finalAmount ; year++) {
		balance += balance * rate;
	}
	cout << "You get " << finalAmount << "$ or more after "
		<< year << " years.\n";

	return 0;

}
