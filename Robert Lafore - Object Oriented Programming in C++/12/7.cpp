#include <iostream>
#include <string>
#include <fstream>


class Name {

private:
	static std::fstream f;

	long id;
	std::string name;
	std::string surname;

public:
	Name() : id(0), name(""), surname("") {}

	void getName(long i, std::string n, std::string sn);
	void writeName();
	void displayName();

	static void openFile(std::string file_name);
	static void setPos(int pos);
	static Name* readName(long find_id);

};
std::fstream Name::f;


void Name::getName(long i, std::string n, std::string sn) {

	id = i;
	name = n;
	surname = sn;

}

void Name::writeName() {

	f.write(reinterpret_cast<char*>(this), sizeof(Name));

}

void Name::openFile(std::string file_name) {

	f.open(file_name, std::ios::binary | std::ios::app |
		std::ios::in | std::ios::out);

}

void Name::setPos(int pos) {

	f.seekg(pos);

}

Name* Name::readName(long find_id) {

	Name* temp = new Name;
	bool find = false;

	f.seekg(0);
	while (!f.eof()) {
		f.read(reinterpret_cast<char*>(temp), sizeof(Name));
		if (temp->id == find_id) {
			find = true;
			break;
		}
	}

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
	Name::openFile(fileName);

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
			nameObj.writeName();
		}

		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cout << "Do you want to continue? (y/n): ";
		std::cin >> answer;

	} while (answer == 'y' || answer == 'Y');


	long find_id;
	std::cout << "Enter id you want to find: ";
	std::cin >> find_id;

	Name* findObj = Name::readName(find_id);
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
