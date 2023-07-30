#include <iostream>

template <class vtype, class stype>
vtype amax(vtype* arr, stype size) {

	if (size <= 0)
		return 0;
	else if (size == 1)
		return arr[0];

	vtype amax = arr[0];
	for (stype i = 1; i < size; i++)
		if (arr[i] > amax) amax = arr[i];

	return amax;

}


int main() {

	const int SIZE_I = 10;
	const long SIZE_F = 5;

	int iarr[SIZE_I] = { 24, 2431, 2416, 11, 4531, 90234, 421, 146, 1, 654 };
	std::cout << "Int:\nMax value is " << amax(iarr, SIZE_I) << std::endl;

	float farr[SIZE_F] = { 11.2, 1243.1, 54325.345, 14.1, 13.37 };
	std::cout << "\nFloat:\nMax value is " << amax(farr, SIZE_F) << std::endl;

	return 0;

}
