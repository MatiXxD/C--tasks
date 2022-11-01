#include <iostream>
#include <cstring>
using namespace std;

class String {

protected:
    static const int SZ = 80;
    char str[SZ];

public:
    String() {
        str[0] = '\0';
    }

    void SetString(const char s[], unsigned int n) {
        strncpy(str, s, n);
        str[n] = '\0';
    }

    void display() const {
        cout << str;
    }

    operator char* () {
        return str;
    }

};

class PString : public String {

public:
    PString(const char s[]) {
        if (strlen(s) > SZ - 1) {
            SetString(s, SZ - 1);
        }
        else {
            SetString(s, strlen(s));
        }
    }

};


int main() {

    PString s1 = "This is a very long string which is probably "
        "no, certainly--going to exceed the limit set by SZ.";
     cout << "\ns1="; s1.display();

    PString s2 = "This is a short string.";
    cout << "\ns2="; s2.display();
    cout << endl;

    return 0;

}
