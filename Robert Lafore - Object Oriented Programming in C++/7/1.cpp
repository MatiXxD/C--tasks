#include <iostream>
#include <cstring>
using namespace std;

void reversit(char str[]);

int main() {

	const int MAX = 80;
	char str[MAX];

	cout << "Enter some text: ";
	cin.get(str, MAX);

	cout << "Reversed string is: ";
	reversit(str);
	cout << str << endl;

	return 0;

}

void reversit(char str[]) {

	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		char temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}

}
