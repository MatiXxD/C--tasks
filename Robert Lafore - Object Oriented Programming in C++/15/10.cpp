#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>


void fillVector(std::vector<int>& vec) {

	std::cout << "Enter vector values: ";
	std::istream_iterator<int> isiter(std::cin), eos;
	std::copy(isiter, eos, std::back_inserter(vec));

}


int main() {

	int start, end, dest;
	std::vector<int> vec;

	fillVector(vec); std::cin.clear(); std::cin.ignore();
	std::cout << "Enter interval: ";
	std::cin >> start >> end; std::cin.clear(); std::cin.ignore();
	std::cout << "Enter destination: ";
	std::cin >> dest; std::cin.clear(); std::cin.ignore();

	start--; dest--;
	if (end - start <= vec.size() - dest)
		std::copy(vec.begin() + start, vec.begin() + end, vec.begin() + dest);
	else {
		std::copy_backward(vec.begin() + start, vec.begin() + end, vec.begin() + dest + 1);
	}

	for (int num : vec)
		std::cout << num << ' ';
	std::cout << std::endl;

	return 0;

}