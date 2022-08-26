#include <iostream>
using namespace std;

int globalCount = 0;

void printStatic();
void printGlobal();


int main() {

	int n;
	cout << "Enter number of repeats: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		printStatic();
		printGlobal();
	}

	return 0;

}


void printStatic() {

	static int staticCount = 0;
	cout << "Function with static value: call "
		<< ++staticCount << endl;

}

void printGlobal() {

	cout << "Function with global value: call "
		<< ++globalCount << endl;
}
