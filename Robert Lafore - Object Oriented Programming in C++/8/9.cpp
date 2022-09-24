#include <iostream>
#include <cstdlib>
using namespace std;

class SafeArray {

private:
	static const int SIZE = 100;
	int arr[SIZE];
	int startInd;
	int endInd;

public:
	SafeArray() : startInd(0), endInd(99) {}

	SafeArray(int s, int e) : startInd(s), endInd(e) {
		if (e - s >= SIZE || e - s < 0) {
			cout << "Wrong indexes.\n";
			exit(1);
		}
	}

	int& operator [] (int n) {
		if (n > endInd || n < startInd) {
			cout << "Wrong indexes.\n";
			exit(1);
		}
		return arr[n - startInd];
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
