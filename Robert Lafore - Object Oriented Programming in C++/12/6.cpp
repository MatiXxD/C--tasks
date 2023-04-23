#include <iostream>
#include <string>
#include <fstream>


class Name {

private:
	long id;
	std::string name;
	std::string surname;

public:
	Name() : id(0), name(""), surname("") {}

	void getName(long i, std::string n, std::string sn);
	void writeName(std::string file_name);
	static Name* readName(std::string file_name, long find_id);
	void displayName();

};

void Name::getName(long i, std::string n, std::string sn) {

	id = i;
	name = n;
	surname = sn;

}

void Name::writeName(std::string file_name) {

	std::ofstream fout(file_name, std::ios::binary | std::ios::app | std::ios::in);

	if (fout) {
		fout.write(reinterpret_cast<char*>(this), sizeof(Name));
	}
	else {
		std::cout << "Can't open file " << file_name << std::endl;
	}

	fout.close();

}

Name* Name::readName(std::string file_name, long find_id) {

	Name* temp = new Name;
	std::ifstream fin(file_name, std::ios::binary);

	bool find = false;
	if (fin) {
		while (!fin.eof()) {
			fin.read(reinterpret_cast<char*>(temp), sizeof(Name));
			if (temp->id == find_id) {
				find = true;
				break;
			}
		}
	}
	else {
		std::cout << "Can't open file " << file_name << std::endl;
	}

	fin.close();

	if (!find) {
		return NULL;
	}
	else {
		return temp;
	}

}

void Name::displayName() {

	std::cout << name << ' ' << surname << " : " << id;

}


///////////////////////////////////////////////////////////////

bool badname(std::string name);



int main() {

	std::string fileName = "base.dat";

	Name nameObj;
	long id;
	std::string name, surname;

	char answer;
	do {

		std::cout << "Enter employee data (name surname id): ";
		std::cin >> name >> surname >> id;
		if (!std::cin.good() || badname(name) || badname(surname)) {
			std::cout << "Wrong input.\n";
		}
		else {
			nameObj.getName(id, name, surname);
			nameObj.writeName(fileName);
		}

		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cout << "Do you want to continue? (y/n): ";
		std::cin >> answer;

	} while (answer == 'y' || answer == 'Y');


	long find_id;
	std::cout << "Enter id you want to find: ";
	std::cin >> find_id;

	Name* findObj = Name::readName(fileName, find_id);
	if (findObj) {
		findObj->displayName(); std::cout << std::endl;
	}
	else {
		std::cout << "Person with id " << find_id << " wasn't found.\n";
	}

	return 0;

}


bool badname(std::string name) {

	for (int i = 0; i < name.size(); i++)
		if (!std::isalpha(name[i])) return true;

	return false;

}
