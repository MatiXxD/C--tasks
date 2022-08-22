#include <iostream>
using namespace std;

enum Etype {
	laborer, secretary, manager,
	accountant, executive, researcher};

int main() {

	Etype type;
	char ch;

	cout << "Enter employee type (first letter only)\n"
		<< "laborer, secretary, manager,\n"
		<< "accountant, executive, researcher): ";
	cin >> ch;

	switch (ch) {
	case 'l':	type = laborer;		break;
	case 's':	type = secretary;	break;
	case 'm':	type = manager;		break;
	case 'a':	type = accountant;	break;
	case 'e':	type = executive;	break;
	case 'r':	type = researcher;	break;
	default:	exit(1);			break;
	}

	cout << "Employee type is ";
	switch (type) {
	case laborer:		cout << "laborer.\n";		break;
	case secretary:		cout << "secretary.\n";		break;
	case manager:		cout << "manager.\n";		break;
	case accountant:	cout << "accountant.\n";	break;
	case executive:		cout << "executive.\n";		break;
	case researcher:	cout << "researcher.\n";	break;
	}

	return 0;

}
