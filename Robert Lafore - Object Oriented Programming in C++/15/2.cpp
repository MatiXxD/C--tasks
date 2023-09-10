#include <iostream>
#include <deque>
#include <algorithm>


int main() {

	std::deque<std::string> dq;

	std::cout << "Enter words: ";
	do {
		std::string temp;
		std::cin >> temp; 
		dq.push_back(temp);
	} while (!std::cin.eof());

	std::sort(dq.begin(), dq.end(), std::less<std::string>());
	for (int i = 0; i < dq.size(); i++) {
		std::cout << dq[i] << std::endl;
	}

	return 0;

}