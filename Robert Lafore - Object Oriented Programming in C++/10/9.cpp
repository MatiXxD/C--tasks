#include <iostream>
using namespace std;

int main() {

	const int SIZE = 10;
	int a0[SIZE], a1[SIZE], a2[SIZE], a3[SIZE], a4[SIZE],
		a5[SIZE], a6[SIZE], a7[SIZE], a8[SIZE], a9[SIZE];

	int* ap[SIZE] = {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9};

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

	return 0;

}
