#include <iostream>
#include <string>


template <class type>
class SafeArray {

private:
    static const int LIMIT = 10;
    type arr[LIMIT];

public:
    class Error {
    private:
        int badId;
        std::string reason;
    public:
        Error(std::string in_reason, int in_id) : reason(in_reason), badId(in_id) { }
        std::string getReason() { return reason; }
        int getId() { return badId; }
    };

    type& operator [](int n) {

        if (n < 0 || n >= LIMIT) {
            throw Error("Out of array boundaries.", n);
        }

        return arr[n];

    }

};

int main() {

    const int LIMIT = 10;

    try {

        // INT
        SafeArray<int> sa_i; std::cout << "INT TEST:\n";
        for (int j = 0; j < LIMIT; j++)
            sa_i[j] = j * 10;
        for (int j = 0; j < LIMIT; j++)
            std::cout << "Element " << j << " is " << sa_i[j] << std::endl;
        std::cout << std::endl;

        // DOUBLE
        SafeArray<double> sa_d; std::cout << "DOUBLE TEST:\n";
        for (int j = 0; j < LIMIT; j++)
            sa_d[j] = j * 1.1;
        for (int j = 0; j < LIMIT; j++)
            std::cout << "Element " << j << " is " << sa_d[j] << std::endl;
        std::cout << std::endl;

        // ERROR HERE
        sa_d[LIMIT] = 11.11;
        //sa_i[LIMIT+1] = 11;

    }
    catch (SafeArray<double>::Error err) {
        std::cout << "Error in DOUBLE array\nReason: " << err.getReason() << std::endl;
        std::cout << "Bad index: " << err.getId() << std::endl;
    }
    catch (SafeArray<int>::Error err) {
        std::cout << "Error in INT array\nReason: " << err.getReason() << std::endl;
        std::cout << "Bad index: " << err.getId() << std::endl;
    }

    return 0;

}
