#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <functional>

int main() {

	std::list < std::string > names;
	
	std::cout << "Enter names: ";
	std::istream_iterator<std::string> isiter(std::cin), eos;
	std::copy(isiter, eos, std::inserter(names, names.begin()));
	std::cin.clear(); std::cin.ignore();

	std::string name;
	std::cout << "Enter name you want to find: ";
	std::cin >> name; std::cin.clear(); std::cin.ignore();

	std::list<std::string>::iterator iter =
		std::find_if(names.begin(), names.end(), std::bind2nd(std::equal_to<std::string>(), name));

	if (iter != names.end()) {
		std::cout << "Find " << name << " at pos (start form 0): " 
			<< std::distance(names.begin(), iter) << std::endl;
	}
	else {
		std::cout << "Name " << name << " wasn't found.\n";
	}

	return 0;

}