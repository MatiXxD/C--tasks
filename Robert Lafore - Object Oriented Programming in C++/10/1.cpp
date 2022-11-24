#include <iostream>
using namespace std;

int main() {

	int n;
	cout << "Enter count of numbers: ";
	cin >> n;

	// Fill array
	float* arr = new float[n];
	for (int i = 0; i < n; i++) {
		cout << "Number" << i + 1 << ": ";
		cin >> *(arr + i);
	}

	// Get mean value
	float sum = 0.0F;
	for (int i = 0; i < n; i++)
		sum += *(arr + i);
	cout << "Mean value: " << sum / n << endl;

	return 1;

}
