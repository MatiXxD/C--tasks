#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int cmpstr(const char const* s1, const char const* s2);

int main() {

	int len1, len2;
	string s1, s2;
	char answer;

	cout << "Press enter to start";
	do {

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Enter first string: "; getline(cin, s1, '\n');
		cout << "Enter second string: "; getline(cin, s2, '\n');

		cout << cmpstr(s1.c_str(), s2.c_str()) << ' ' << strcmp(s1.c_str(), s2.c_str()) << endl;
		cout << "Do you want to continue (y / n): ";
		cin >> answer;

	} while (answer == 'y');

	return 0;

}

int cmpstr(const char const* s1, const char const* s2) {

	const char* c1 = s1;
	const char* c2 = s2;
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	if (len1 != len2)
		return len1 > len2 ? 1 : -1;

	while (*c1 && *c2)
		if (*c1++ != *c2++)
			return *(--c1) > *(--c2) ? 1 : -1;

	return 0;

}
