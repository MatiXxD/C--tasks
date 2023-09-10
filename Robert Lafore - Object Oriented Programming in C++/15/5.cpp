#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>


int fillArray(double** arr) {

	int size;

	std::cout << "Enter size:\n";
	std::cin >> size;
	if (size <= 0) return 0;

	*arr = new double[size];
	std::cout << "Enter " << size << " values:\n";
	for (int i = 0; i < size; i++)
		std::cin >> (*arr)[i];
	std::cin.clear(); std::cin.ignore();

	return size;

}

void fillSet(std::set< double, std::less<double> >& st) {

	std::cout << "Enter values for set:\n";

	std::istream_iterator<double> isiter(std::cin);
	std::istream_iterator<double> iseos;
	std::copy(isiter, iseos, std::inserter(st, st.begin()));

}

void printVec(std::vector<double> vec) {

	std::ostream_iterator<double> ositer(std::cout, " ");
	std::copy(vec.begin(), vec.end(), ositer);

}


int main() {

	double* arr = NULL; 
	int size = fillArray(&arr); std::cout << std::endl;

	std::set< double, std::less<double> > st;
	fillSet(st); std::cout << std::endl;

	std::vector<double> vec;
	std::merge(arr, arr + size, st.begin(), st.end(), std::back_inserter(vec));
	std::cout << "Merged:\n"; printVec(vec);

	return 0;

}