#include <iostream>
#include <string>

template <class Type>
class Queue {

private:
    static const int MAX = 3;
    int count, head, tail;

    Type qu[MAX];

public:
    class ErrorQueue {
    public:
        std::string reason;
        ErrorQueue(std::string in_reason) : reason(in_reason) { }
    };

    Queue() : head(-1), tail(-1), count(0) {

    }

    void put(Type var) {

        if (count >= MAX)
            throw ErrorQueue("Queue is full.\n");
        count++;

        qu[++tail] = var;
        if (tail >= MAX - 1)
            tail = -1;

    }

    Type get() {

        if (count <= 0)
            throw ErrorQueue("Queue is empty.\n");
        count--;

        Type temp = qu[++head];
        if (head >= MAX - 1)
            head = -1;

        return temp;

    }

};


int main() {

    Queue<float> queue;

    char answer; float value;
    do {

        try {

            std::cout << "What to do (add-a/delete-d): ";
            std::cin >> answer; std::cin.clear(); std::cin.ignore();

            if (tolower(answer) == 'a') {
                std::cout << "Enter value: ";
                std::cin >> value;
                queue.put(value);
            }
            else if (tolower(answer) == 'd') {
                std::cout << "Get value: " << queue.get() << std::endl;
            }
            else {
                std::cout << "Wrong command.\n";
            }

        } catch (Queue<float>::ErrorQueue err) {
            std::cout << "Reason: " << err.reason;
        }

        std::cout << "Do you want to continue (y/n): ";
        std::cin >> answer; std::cin.clear(); std::cin.ignore();

    } while(tolower(answer) == 'y');

	return 0;

}
