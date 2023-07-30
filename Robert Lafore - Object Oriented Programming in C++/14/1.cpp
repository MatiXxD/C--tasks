#include <iostream>
#include <cstdlib>

template <class type>
type avg(type* arr, int size) {

	type total = 0;
	for (int i = 0; i < size; i++)
		total += arr[i];

	return static_cast<type>(total / size);

}

int main() {

	const int SIZE = 15;

	int iarr[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	long larr[SIZE] = { 43214, 78354, 89211, 38593, 1201, 23184, 1284, 1849, 18941, 456, 432190, 412, 941, 8953, 1294};
	double darr[SIZE] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1, 11.11, 12.12, 13.13, 14.14, 15.15 };
	char carr[SIZE] = { 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86 };

	std::cout << "Int average: " << avg(iarr, SIZE) << std::endl;
	std::cout << "Long average: " << avg(larr, SIZE) << std::endl;
	std::cout << "Double average: " << avg(darr, SIZE) << std::endl;
	std::cout << "Char average: " << static_cast<int>(avg(carr, SIZE)) << std::endl;

	return 0;

}
