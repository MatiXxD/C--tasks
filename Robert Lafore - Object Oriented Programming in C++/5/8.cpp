#include <iostream>
using namespace std;

void swap(int& a, int& b);

int main() {

	int a = 5, b = 11;
	int c = 4284, d = 38292;

	cout << "Before swap:\n";
	cout << "a = " << a << '\t' << '\t' << "b = " << b << endl;
	cout << "c = " << c << '\t' << "d = " << d << endl;

	swap(a, b);
	swap(c, d);

	cout << "\nAfter swap:\n";
	cout << "a = " << a << '\t' << '\t' << "b = " << b << endl;
	cout << "c = " << c << '\t' << "d = " << d << endl;

	return 0;

}

void swap(int& a, int& b){

	int temp = a;
	a = b;
	b = temp;

}
