#include <iostream>
#include <fstream>
#include <iterator>


int main() {

	std::string sourceName, destName;

	std::cout << "Enter source file name: "; std::cin >> sourceName;
	std::cout << "Etner destination file name: "; std::cin >> destName;

	std::ifstream fin(sourceName);
	std::ofstream fout(destName);
	std::istream_iterator<int> isiter(fin), eos;
	std::ostream_iterator<int> ositer(fout, " ");

	while (isiter != eos)
		*ositer++ = *isiter++;

	fin.close();
	fout.close();

	return 0;

}