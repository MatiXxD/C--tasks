#include <iostream>

////////////////////////////////////////////////
template <class type>
struct Node {
	type data;
	Node* next;
};
////////////////////////////////////////////////
template <class type>
class Queue {

private:
	Node<type>* end;
	int curSize;

public:
	Queue() {
		end = NULL;
		curSize = 0;
	}

	void add(type val);
	type pop();
	void print();

};

template <class type>
void Queue<type>::add(type val) {

	if (end == NULL) {
		end = new Node<type>;
		end->data = val;
		end->next = NULL;
	}
	else {
		Node<type>* temp = end;
		end = new Node<type>;
		end->data = val;
		end->next = temp;
	}

	curSize++;

}

template <class type>
type Queue<type>::pop() {

	if (end == NULL) {
		std::cerr << "Can't use pop() with an empty queue.";
		exit(1);
	}

	Node<type> *start = end, *prv = NULL;
	while (start->next) {
		prv = start;
		start = start->next;
	}
	if (prv) prv->next = NULL;

	type dltVal = start->data;
	delete start;  curSize--;

	return dltVal;

}

template <class type>
void Queue<type>::print() {

	Node<type>* temp = end;
	while (temp) {
		std::cout << temp->data << ' ';
		temp = temp->next;
	}
	std::cout << std::endl;

}

////////////////////////////////////////////////

int main() {

	Queue<double> queue;

	char answer;
	double val;	// try other type for test
	while (true) {

		std::cout << "Enter value: ";
		std::cin >> val; std::cin.clear(); std::cin.ignore();
		queue.add(val);

		std::cout << "Enter another (y/n): ";
		std::cin >> answer; std::cin.clear(); std::cin.ignore();
		if (answer == 'n') break;

	}

	queue.pop();
	queue.pop();
	queue.print();

	return 0;

}
