#include <iostream>
#include <process.h>


template <class type>
class SafeArray {
private:
    static const int LIMIT = 10;
    type arr[LIMIT];
public:
    type& operator [](int n) {
        if (n < 0 || n >= LIMIT) {
            std::cout << "\nIndex out of bounds"; exit(1);
        }
        return arr[n];
    }

};

int main() {

    const int LIMIT = 10;

    // INT
    SafeArray<int> sa_i; std::cout << "INT TEST:\n";
    for (int j = 0; j < LIMIT; j++)
        sa_i[j] = j * 10;
    for (int j = 0; j < LIMIT; j++)
        std::cout << "Element " << j << " is " << sa_i[j] << std::endl;

    // DOUBLE
    SafeArray<double> sa_d; std::cout << "\nDOUBLE TEST:\n";
    for (int j = 0; j < LIMIT; j++)
        sa_d[j] = j * 1.1;
    for (int j = 0; j < LIMIT; j++)
        std::cout << "Element " << j << " is " << sa_d[j] << std::endl;

    return 0;

}
