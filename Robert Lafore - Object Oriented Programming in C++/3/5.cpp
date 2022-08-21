#include <iostream>

using namespace std;

int main() {

	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 19 - i; j++)
			cout << ' ';
		for (int j = 0; j < 1 + 2 * i; j++)
			cout << 'X';
		cout << endl;

	}

	return 0;

}
