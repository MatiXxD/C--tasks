#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>


void listFill(std::vector<int>& vec) {

	std::istream_iterator<int> isiter(std::cin);
	std::istream_iterator<int> iseos;
	std::copy(isiter, iseos, std::back_inserter(vec));

}

void printList(const std::vector<int>& vec) {

	std::ostream_iterator<int> ositer(std::cout, " ");
	std::copy(vec.begin(), vec.end(), ositer);

}

void reverseList(std::vector<int>& vec) {

	std::vector<int>::iterator begin = vec.begin();
	std::vector<int>::reverse_iterator end = vec.rbegin();

	int count = vec.size() / 2;
	for (int i = 0; i < count; i++)
		std::swap(*begin++, *end++);

}


int main() {

	std::vector<int> vec;

	std::cout << "Enter numbers:\n";
	listFill(vec);

	std::cout << "\nBefore:\n";
	printList(vec);

	std::cout << "\nReversed:\n";
	reverseList(vec); printList(vec);

	return 0;

}