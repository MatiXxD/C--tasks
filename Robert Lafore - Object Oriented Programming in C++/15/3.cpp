#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>


void listFill(std::list<int>& lst) {

	std::istream_iterator<int> isiter(std::cin);
	std::istream_iterator<int> iseos;
	std::copy(isiter, iseos, std::back_inserter(lst));

}

void printList(const std::list<int>& lst) {

	std::ostream_iterator<int> ositer(std::cout, " ");
	std::copy(lst.begin(), lst.end(), ositer);

}

void reverseList(std::list<int>& lst) {

	std::list<int>::iterator begin = lst.begin();
	std::list<int>::iterator end = --lst.end();

	int count = lst.size() / 2;
	for (int i = 0; i < count; i++)
		std::swap(*begin++, *end--);

}


int main() {

	std::list<int> lst;

	std::cout << "Enter numbers:\n";
	listFill(lst);

	std::cout << "\nBefore:\n";
	printList(lst);

	std::cout << "\nReversed:\n";
	reverseList(lst); printList(lst);

	return 0;

}