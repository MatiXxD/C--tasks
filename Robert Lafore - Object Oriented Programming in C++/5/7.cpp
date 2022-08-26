#include <iostream>
using namespace std;

double power(double num, int p = 2);
float power(float num, int p = 2);
long power(long num, int p = 2);
int power(int num, int p = 2);
char power(char num, int p = 2);

int main() {

	int p;
	char answer, type;

	double dNum;
	float fNum;
	long lNum;
	int iNum;
	char cNum;

	cout << "Enter first letter of the type you want to use: ";
	cin >> type;
	cout << "Do you want to change default power (2) y/n: ";
	cin >> answer;
	if (answer == 'y') {
		cout << "Enter power: ";
		cin >> p;
	}
	cout << "Enter number: ";
	switch (type) {
	case 'd':
		cin >> dNum;
		if(answer == 'y')	cout << "Result: " << power(dNum, p);
		else				cout << "Result: " << power(dNum);
		break;
	case 'f':
		cin >> fNum;
		if (answer == 'y')	cout << "Result: " << power(fNum, p);
		else				cout << "Result: " << power(fNum);
		break;
	case 'l':
		cin >> lNum;
		if (answer == 'y')
			cout << "Result: " << power(lNum, p);
		else
			cout << "Result: " << power(lNum);
		break;
	case 'i':
		cin >> iNum;
		if (answer == 'y')
			cout << "Result: " << power(iNum, p);
		else
			cout << "Result: " << power(iNum);
		break;
	case 'c':
		cin >> cNum;
		if (answer == 'y')
			cout << "Result: " << power(cNum, p);
		else
			cout << "Result: " << power(cNum);
		break;
	default:
		cout << "Entered wrong type.";
		break;
	}


	return 0;

}

double power(double num, int p) {

	double res = 1;
	for (int pi = 0; pi < p; pi++)
		res *= num;

	return res;

}

float power(float num, int p) {

	float res = 1;
	for (int pi = 0; pi < p; pi++)
		res *= num;

	return res;

}

long power(long num, int p) {

	long res = 1;
	for (int pi = 0; pi < p; pi++)
		res *= num;

	return res;

}

int power(int num, int p) {

	int res = 1;
	for (int pi = 0; pi < p; pi++)
		res *= num;

	return res;

}

char power(char num, int p) {

	char res = 1;
	for (int pi = 0; pi < p; pi++)
		res *= num;

	return res;

}
