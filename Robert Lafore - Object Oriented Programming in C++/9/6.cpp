#include <iostream>
#include <cstdlib>
using namespace std;

class safearray{

protected:
	static const int LIMIT = 100;

private:
	int arr[LIMIT];

public:
	int& operator [](int n) {
		if (n < 0 || n >= LIMIT) {
			cout << "\nIndex out of bounds";
			exit(1);
		}
		return arr[n];
	}

};

class SafeArray : private safearray {

private:
	int first;
	int last;

public:
	SafeArray() : first(0), last(LIMIT - 1) { }

	SafeArray(int f, int l) {
		if (f >= l) {
			cout << "Wrong index. Exiting.\n";
			exit(1);
		}
		first = f;
		last = l;
	}

	int& operator [](int n) {
		if (n < first || n > last) {
			cout << "Wrong index. Returning first element of array.\n";
			return safearray::operator[](0);
		}
		return safearray::operator[](n);
	}

};

int main() {

	int i1, i2;
	cout << "Enter array indexes: ";
	cin >> i1 >> i2;
	SafeArray arr(i1, i2);

	int val;
	for (int i = i1; i < i2; i++) {
		cout << "Enter value: "; cin >> val;
		arr[i] = val;
	}

	for (int i = i1; i < i2; i++) {
		cout << arr[i] << endl;
	}

	return 0;

}
