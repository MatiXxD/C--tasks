#include <iostream>
#include <string>
#include <cstdlib>


class Distance {

private:
    int feet;
    float inches;

public:
    class Error {
    private:
        std::string reason;
    public:
        Error(std::string in_reason) : reason(in_reason) { }
        std::string getReason() { return reason; }
    };

    Distance() {
        feet = 0; inches = 0.0;
    }

    Distance(int ft, float in) {
        feet = ft; inches = in;
    }

    void showdist() {
        std::cout << feet << "\'-" << inches << '\"';
    }

    void getdist();
    void isFeet(std::string);
    void isInch(std::string);

};

void Distance::getdist() {

    std::string inFeet, inInch;

    std::cout << "Enter feet: ";
    std::cin.unsetf(std::ios::skipws);
    std::cin >> inFeet; std::cin.clear(); std::cin.ignore(10, '\n');
    isFeet(inFeet);
    feet = atoi(inFeet.c_str());

    std::cout << "Enter inches: ";
    std::cin.unsetf(std::ios::skipws);
    std::cin >> inInch; std::cin.clear(); std::cin.ignore(10, '\n');
    isInch(inInch);
    inches = atof(inInch.c_str());

}

void Distance::isFeet(std::string str) {

    int slen = str.length();
    if (slen == 0 || slen > 5)
        throw Error("Wrong feet input. Number is too big or entered an empty string.");

    for (int j = 0; j < slen; j++)
        if ((str[j] < '0' || str[j] > '9') && str[j] != '-')
            throw Error("Wrong feet input. String consists of invalid symbols.");

    double n = atof(str.c_str());
    if (n < -999.0 || n>999.0)
        throw Error("Wrong feet input. Value is too big (to low).");

}

void Distance::isInch(std::string str) {

    int dotCount = 0;
    for (int j = 0; j < str.length(); j++) {
        if (str[j] == '.') {
            dotCount++;
            if (dotCount >= 2) throw Error("Wrong inches input. Find two or more '.' sympols.");
        }
        else if ((str[j] < '0' || str[j] > '9') && str[j] != '-')
            throw Error("Wrong inches input. String consists of invalid symbols.");
    }

    double n = atof(str.c_str());
    if (n < 0.0 || n >= 12.0)
        throw Error("Wrong inches input. Value is too big (to low).");

}


int main() {

    Distance d;
    char ans;
    do {

        try {
            d.getdist();
            std::cout << "Distance = ";
            d.showdist(); std::cout << std::endl;
        }
        catch (Distance::Error err) {
            std::cout << "ERROR!\n" << err.getReason() << std::endl;
        }

        std::cout << "\nDo another (y/n)? ";
        std::cin >> ans; std::cin.clear(); std::cin.ignore(10, '\n');

    } while (ans != 'n');

    return 0;

}
