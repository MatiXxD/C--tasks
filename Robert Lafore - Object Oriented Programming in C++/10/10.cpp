#include <iostream>
using namespace std;

int main() {

	const int SIZE = 10;
	int** ap;

	// Allocate memory
	ap = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
		ap[i] = new int[SIZE];

	// Fill arrays
	for (int k = 0; k < SIZE; k++)
		for (int i = 0; i < SIZE; i++)
			ap[k][i] = k * SIZE + i;

	// Print arrays
	for (int k = 0; k < SIZE; k++) {
		cout << "Array " << k + 1 << ":\t";
		for (int i = 0; i < SIZE; i++)
			cout << ap[k][i] << ' ';
		cout << endl;
	}

	// Delete memory
	for (int i = 0; i < SIZE; i++)
		delete[] ap[i];
	delete[] ap;

	return 0;

}
