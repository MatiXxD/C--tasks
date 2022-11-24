#include <iostream>
using namespace std;

void fillArray(double** arr, unsigned size);
double* sumArrs(double const* arr1, double const* arr2, unsigned size);
void printArray(double const* arr, unsigned size);


int main() {

	unsigned size;
	cout << "Enter arrays' size: ";
	cin >> size;

	double* arr1 = NULL; fillArray(&arr1, size);
	double* arr2 = NULL; fillArray(&arr2, size);
	double* arr3 = sumArrs(arr1, arr2, size);
	printArray(arr1, size);
	printArray(arr2, size);
	printArray(arr3, size);

	delete[] arr3;
	delete[] arr2;
	delete[] arr1;

	return 0;

}


void fillArray(double** arr, unsigned size) {

	*arr = new double[size];
	cout << "Enter array's elements: ";
	for (int i = 0; i < size; i++)
		cin >> *(*arr + i);

}

double* sumArrs(double const* arr1, double const* arr2, unsigned size) {

	double* sum = new double[size];
	for (int i = 0; i < size; i++)
		*(sum + i) = *(arr1 + i) + *(arr2 + i);

	return sum;

}

void printArray(double const* arr, unsigned size) {

	for (int i = 0; i < size; i++)
		cout << *(arr + i) << ' ';
	cout << endl;

}
