#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <iterator>


class Histogram {

private:
	std::ifstream fin;
	std::map<std::string, int> dict;

	std::string parseWord(std::string word);


public:
	Histogram(std::string fileName);
	void readFile();
	void printHist();

};

Histogram::Histogram(std::string fileName) {

	fin.open(fileName);
	this->readFile();

}

std::string Histogram::parseWord(std::string word) {

	std::for_each(word.begin(), word.end(), std::tolower);

	for(int i = word.length() - 1 ; i >= 0 ; i--)
		if (std::ispunct(word[i]))
			word.erase(word.begin() + i);

	return word;

}

void Histogram::readFile() {

	std::istream_iterator<std::string> isiter(fin), eos;
	while (isiter != eos) {
		std::string temp = parseWord(*isiter++);
		dict[temp] += 1;
	}

}

void Histogram::printHist() {

	std::map<std::string, int>::iterator iter = dict.begin();
	while (iter != dict.end()) {
		std::cout << (*iter).first << '\t' << (*iter).second << std::endl;
		iter++;
	}

}


int main() {

	std::string fileName;

	std::cout << "Enter file name: ";
	std::cin >> fileName; std::cin.clear(); std::cin.ignore();

	Histogram hist(fileName);
	hist.printHist();

	return 0;

}