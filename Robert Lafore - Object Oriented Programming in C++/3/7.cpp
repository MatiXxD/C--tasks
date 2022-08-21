#include <iostream>

using namespace std;

int main() {

	double balance, rate, years;
	cout << "Enter initial amount: ";
	cin >> balance;
	cout << "Enter number of years: ";
	cin >> years;
	cout << "Enter interest rate (percent per year): ";
	cin >> rate;
	rate /= 100;

	for (int year = 0; year < years; year++) {
		balance += balance * rate;
	}
	cout << "At the end of " << years << " years, you will have "
		<< balance << " dollars.\n";

	return 0;

}
