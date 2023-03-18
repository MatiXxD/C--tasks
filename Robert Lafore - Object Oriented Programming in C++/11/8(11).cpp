#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>


/////////////////////////////////////////////////////////////////////////////////////////////////////////
class Token {

public:
	virtual double getNumber() = 0;
	virtual char getOperator() = 0;

};

class Number : public Token {

private:
	double number;

public:
	Number(double num) : number(num) {

	}

	double getNumber() {
		return number;
	}

	char getOperator() {
		return '0';
	}

};

class Operator : public Token {

private:
	char oper;

public:
	Operator(char ch) : oper(ch) {

	}

	double getNumber() {
		return 0.0;
	}

	char getOperator() {
		return oper;
	}

};


/////////////////////////////////////////////////////////////////////////////////////////////////////////
class Stack {

private:
	Token* stack[100];
	int top;

public:
	Stack() {
		top = 0;
	}

	void push(Token* val) {
		stack[++top] = val;
	}

	Token* pop() {
		return stack[top--];
	}

	int getTop() {
		return top;
	}

};


/////////////////////////////////////////////////////////////////////////////////////////////////////////
class Express {

private:
	Stack stack;
	std::string s;

public:
	Express(std::string s_in) : s(s_in) { }
	void dltPart();
	void parse();
	double solve();

};

void Express::dltPart() {

	while ((s[0] >= '0' && s[0] <= '9') || s[0] == '.') {
		s.erase(0, 1);
	}

}

void Express::parse() {

	Token* tn1;
	Token* tn2;
	Token* to;

	double dval;
	char cval;
	int operator_num = 0;

	std::istringstream stream(s);
	while (s.length() != 0) {

		cval = s[0];

		if (cval >= '0' && cval <= '9') {
			stream >> dval;
			if (stack.getTop() == 0) {
				operator_num++;
				stack.push(new Operator('+'));
			}
			stack.push(new Number(dval));
			this->dltPart();
		}

		else if (cval == '+' || cval == '-' || cval == '*' || cval == '/') {

			stream >> cval;

			if (operator_num < 2) stack.push(new Operator(cval));

			else {
				tn2 = stack.pop();
				to = stack.pop();

				if ((cval == '*' || cval == '/') && (to->getOperator() == '+' || to->getOperator() == '-')) {
					stack.push(to);
					stack.push(tn2);
 					stack.push(new Operator(cval));
				}

				else {

					tn1 = stack.pop();
					switch (to->getOperator()) {

					case '+':
						stack.push(new Number(tn1->getNumber() + tn2->getNumber()));
						break;

					case '-':
						stack.push(new Number(tn1->getNumber() - tn2->getNumber()));
						break;

					case '*':
						stack.push(new Number(tn1->getNumber() * tn2->getNumber()));
						break;

					case '/':
						if (tn2->getNumber() == 0.0) {
							std::cout << "Can't divide by 0!\n";
							exit(1);
						}
						stack.push(new Number(tn1->getNumber() / tn2->getNumber()));
						break;

					}

					stack.push(new Operator(cval));

					delete tn1;
					delete tn2;
					delete to;

				}

			}

			operator_num++;
			s.erase(0, 1);

		}

		else {
			std::cout << "Wrong input!";
		}

	}

}

double Express::solve() {

	Token *to1, *to2;
	Token *tn1, *tn2;

	double num1, num2;
	while (stack.getTop() > 2) {

		tn2 = stack.pop();
		to2 = stack.pop();
		tn1 = stack.pop();
		to1 = stack.pop();

		num2 = tn2->getNumber();
		num1 = to1->getOperator() == '-' ? -tn1->getNumber() : tn1->getNumber();

		stack.push(to1);
		switch (to2->getOperator()) {

		case '+':
			stack.push(new Number(abs(num1 + num2)));
			break;

		case '-':
			stack.push(new Number(abs(num1 - num2)));
			break;

		case '*':
			stack.push(new Number(abs(num1 * num2)));
			break;

		case '/':
			if (num2 == 0.0) {
				std::cout << "Can't divide by 0!\n";
				exit(1);
			}
			stack.push(new Number(abs(num1 / num2)));
			break;

		}

		delete tn1;
		delete tn2;
		delete to2;

	}

	tn1 = stack.pop();
	to1 = stack.pop();
	double res = tn1->getNumber();
	delete tn1; delete to1;

	return res;

}


int main() {

	char ans;
	std::string str;

	std::cout << "THE PROGRAM HAS STARTED\n\n";
	do {

		std::cout << "Enter expresssion: ";
		std::cin >> str;
		Express* eptr = new Express(str);

		eptr->parse();
		std::cout << "Result is: " << eptr->solve() << std::endl;
		delete eptr;

		std::cout << "Do another (Enter y or n)? ";
		std::cin >> ans;

	} while (ans == 'y');

	return 0;

}
