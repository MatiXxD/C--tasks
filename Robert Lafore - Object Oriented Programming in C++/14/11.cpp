#include <iostream>
#include <string.h>
#include <stdlib.h>

class String {

private:
    enum { SZ = 80 };
    char str[SZ];

public:
    class Error {
    private:
        std::string where;
        std::string reason;
    public:
        Error(std::string where_in, std::string reason_in) :
            where(where_in), reason(reason_in) { }
        void printError() {
            std::cout << "In: " << where << std::endl <<
                "Reason: " << reason << std::endl;
        }
    };

    String() {
        strcpy(str, "");
    }

    String(const char s[]) {
        if (strlen(s) > SZ)
            throw Error("One argument constructor.", "Size is too big.");
        strcpy(str, s);
    }

    void display() const {
        std::cout << str;
    }

    String operator + (String ss) const {

        String temp;

        if (strlen(str) + strlen(ss.str) < SZ) {
            strcpy(temp.str, str);
            strcat(temp.str, ss.str);
        }
        else {
            throw Error("Operator '+'.", "Size is too big.");
        }

        return temp;

    }

};



int main() {

    try {
        String s1 = "qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyuiop[]asdfghjkl;'zxcvbnm,./qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    }
    catch (String::Error err) {
        err.printError(); std::cout << std::endl;
    }

    try {
        String s1 = "qwertyuiop[]asdfghjkl;'zxcvbnm";
        String s2 = "qwertyuiop[]asdfghjkl;'zxcvbnmqwertyuiop[]asdfghjkl;'zxcvbnm";
        String s3 = s1 + s2;
    }
    catch (String::Error err) {
        err.printError(); std::cout << std::endl;
    }

    return 0;

}
