#include <iostream>
using namespace std;

double power(double num, int p = 2);

int main(){

	double num, result;
	int p;
	char answer;

	cout << "Enter number: ";
	cin >> num;
	cout << "Do you want to change power (default=2) y or n: ";
	cin >> answer;
	if (answer == 'y') {
		cout << "Enter new power: ";
		cin >> p;
		result = power(num, p);
	}
	else {
		result = power(num);
	}

	cout << "Result: " << result << endl;

	return 0;

}

double power(double num, int p) {

	double res = 1;
	for (int pi = 0; pi < p; pi++)
		res *= num;

	return res;

}
