#include <iostream>
#include <fstream>


int main(int argc, char* argv[]) {

	if (argc != 3) {
		std::cout << "Input: a.exe source distance.\nShould be 2 args!";
		return 1;
	}

	std::ifstream fin;	fin.open(argv[1]);
	std::ofstream fout;	fout.open(argv[2]);

	fout << fin.rdbuf();

	fin.close();
	fout.close();

	return 0;

}
