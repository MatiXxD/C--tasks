#include <iostream>
using namespace std;

class CountObj {

private:
	static unsigned total;
	unsigned num;

public:
	CountObj() {
		num = ++total;
	}

	void display() const {
		cout << "I am object number " << num << endl;
	}

};

unsigned CountObj::total = 0;


int main() {

	CountObj obj1, obj2, obj3;

	obj1.display();
	obj2.display();
	obj3.display();

	return 0;

}
