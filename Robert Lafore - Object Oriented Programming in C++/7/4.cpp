#include <iostream>
using namespace std;

int maxInt(int arr[], int size);

int main() {

	const int SIZE = 100;
	int arr[SIZE];
	char answer;

	int count = 0;
	do {

		cout << "Enter number: ";
		cin >> arr[count++];
		if (count >= SIZE) break;

		cout << "Do you want to continue (y / n): ";
		cin >> answer;

	} while (answer == 'y');

	int maxInd = maxInt(arr, count);
	cout << "Max element is " << arr[maxInd] << " it's position is "
		<< maxInd << endl;

	return 0;

}

int maxInt(int arr[], int size) {

	int maxInd = 0;

	for (int i = 0; i < size; i++)
		if (arr[i] > arr[maxInd])
			maxInd = i;

	return maxInd;

}
