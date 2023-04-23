#include <iostream>
#include <fstream>


int main(int argc, char* argv[]) {

	if (argc != 2) {
		std::cout << "Input: a.exe file.\nShould be 1 arg!";
		return 1;
	}

	std::ifstream f(argv[1]);
	if (f.good()) {
		f.seekg(0, std::ios::end);
		std::cout << "Size is " << f.tellg() << std::endl;
	}
	else {
		std::cout << "Can't open file " << argv[1] << std::endl;
	}

	f.close();

	return 0;

}
