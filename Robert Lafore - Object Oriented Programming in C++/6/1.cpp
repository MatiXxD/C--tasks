#include <iostream>
using namespace std;

class Int {

private:
	int val;

public:
	Int() : val(0) { }
	Int(int num) : val(num) { }
	void displayVal() const{
		cout << val;
	}
	Int addVal(const Int num2) const;

};

Int Int::addVal(const Int num2) const{

	Int sum(val + num2.val);

	return sum;

}


int main() {

	Int num1(5), num2(14), num3;

	num3 = num1.addVal(num2);

	num1.displayVal(); cout << " + ";
	num2.displayVal(); cout << " = ";
	num3.displayVal(); cout << endl;

	return 0;

}
