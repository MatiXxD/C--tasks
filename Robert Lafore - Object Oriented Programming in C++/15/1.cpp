#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


void getValues(std::vector<float>& vec) {

	std::istream_iterator<float> iter(std::cin);
	std::istream_iterator<float> eos;

	std::copy(iter, eos, std::inserter(vec, vec.begin()));

}

void printVec(std::vector<float>& vec) {

	std::ostream_iterator<float> iter(std::cout, " ");
	
	std::copy(vec.begin(), vec.end(), iter);

}


int main() {

	std::vector<float> vec;

	std::cout << "Enter value (EOF to stop):\n";
	getValues(vec);

	std::cout << "\nBefore:\n";
	printVec(vec);

	std::cout << "\nAfter sort:\n";
	std::sort(vec.begin(), vec.end(), std::less<float>());
	printVec(vec);

	return 0;

}