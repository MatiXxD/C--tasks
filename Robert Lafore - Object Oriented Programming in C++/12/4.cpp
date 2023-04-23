#include <iostream>
#include <fstream>


bool badname(std::string name) {

	for (int i = 0; i < name.size(); i++)
		if (!std::isalpha(name[i])) return true;

	return false;

}


int main() {

	std::string name, surname;
	long id;
	char answer;

	std::ofstream fout("data.txt");
	do {

		std::cout << "Enter employee data (name surname id): ";
		std::cin >> name >> surname >> id;
		if (!std::cin.good() || badname(name) || badname(surname)) {
			std::cout << "Wrong input.\n";
		}
		else {
			fout << name << ' ' << surname << " : " << id << '\n';
		}

		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cout << "Do you want to continue? (y/n): ";
		std::cin >> answer;

	} while (answer == 'y' || answer == 'Y');
	fout.close();


	std::ifstream fin("data.txt", std::ios::app);
	std::cout << fin.rdbuf();
	fin.close();

	return 0;

}
