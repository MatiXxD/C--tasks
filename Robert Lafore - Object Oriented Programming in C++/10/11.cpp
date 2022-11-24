#include <iostream>
using namespace std;

class Array {

private:
	static const int SIZE = 10;
	int** arr;

public:
	Array() {
		arr = new int* [SIZE];
		for (int i = 0; i < SIZE; i++)
			arr[i] = new int[SIZE];
	}

	~Array() {
		for (int i = 0; i < SIZE; i++)
			delete[] arr[i];
		delete[] arr;
	}

	int& operator[](int i) {
		int k = i / 10;
		int j = i - k * 10;
		return arr[k][j];
	}

};


int main() {

	Array arr;

	for (int i = 0; i < 100; i++)
		arr[i] = i + 1;
	for (int i = 0; i < 100; i++)
		cout << arr[i] << (!((i + 1) % 10) ? '\n' : ' ');

	return 0;

}
