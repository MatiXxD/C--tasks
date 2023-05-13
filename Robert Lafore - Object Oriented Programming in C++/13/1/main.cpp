#include "verylong.h"                 


int main() {

    char answer, operation;
    string num1, num2;
    bool flag = true;

    do {

        std::cout << "Enter first number: "; std::cin >> num1;
        std::cout << "Enter operation: "; std::cin >> operation;
        std::cout << "Enter second number: "; std::cin >> num2;

        verylong n1(num1), n2(num2), n3;
        switch (operation) {
        case '+': n3 = n1 + n2; break;
        case '-': n3 = n1 - n2; break;
        case '*': n3 = n1 * n2; break;
        case '/': n3 = n1 / n2; break;
        default: std::cout << "Wrong operation.\n"; flag = false;
        }

        if (flag) {
            std::cout << num1 << operation << num2 << "=";
            n3.putvl(); std::cout << std::endl;
        }

        std::cout << "Do you want to continue: ";
        std::cin.clear(); std::cin.ignore(1024, '\n');
        std::cin >> answer;

    } while (answer == 'y' || answer == 'Y');

    return 0;

}
