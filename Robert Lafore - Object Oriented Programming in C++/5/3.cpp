#include <iostream>
using namespace std;

void zeroSmaller(int& a, int& b);

int main(){

	int a = 1;
	int b = 3;
	int c = 12;
	int d = 5;

	cout << "a = " << a << " | " << "b = " << b << endl;
	cout << "c = " << c << " | " << "d = " << d << endl;
	zeroSmaller(a, b);
	zeroSmaller(c, d);
	cout << "a = " << a << " | " << "b = " << b << endl;
	cout << "c = " << c << " | " << "d = " << d << endl;

	return 0;

}

void zeroSmaller(int& a, int& b) {

	if (a < b)
		a = 0;
	else
		b = 0;

}
