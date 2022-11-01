#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
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

    String(const char s[], unsigned int n) {
        strncpy(str, s, n);
        str[n] = '\0';
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
    PString() : String() {}
    PString(const char s[]) {
        if (strlen(s) > SZ - 1) {
            SetString(s, SZ - 1);
        }
        else {
            SetString(s, strlen(s));
        }
    }

};

class PString2 : public PString {

public:
    PString2() : PString() {}
    PString2(const char s[]) : PString(s) {}

    PString2 left(PString2 s1, unsigned int n);
    PString2 mid(PString2 s1, unsigned int s, unsigned int n);
    PString2 right(PString2 s1, unsigned int n);

};

PString2 PString2::left(PString2 s1, unsigned int n) {

    if (n > SZ) {
        cout << "You reached the limit. n value set to SZ - 1.\n";
        n = SZ - 1;
    }
    else if (n > strlen(s1)) {
        cout << "You reached the limit. n value set to strlen(s1).\n";
        n = strlen(s1) - 1;
    }

    int i;
    for (i = 0; i < n; i++) {
        str[i] = s1[i];
    }
    str[i] = '\0';

    return PString2(str);

}

PString2 PString2::mid(PString2 s1, unsigned int s, unsigned int n) {

    if (n > SZ) {
        cout << "You reached the limit. n value set to SZ - 1.\n";
        n = SZ - 1;
    }
    else if (n > strlen(s1)) {
        cout << "You reached the limit. n value set to strlen(s1).\n";
        n = strlen(s1) - 1;
    }
    else if (strlen(s1) - s < n) {
        cout << "Wrong value for s. Set 0 for s value by default.\n";
        s = 0;
    }

    int i;
    for (i = 0; i < n; i++) {
        str[i] = s1[s+i];
    }
    str[i] = '\0';

    return PString2(str);

}

PString2 PString2::right(PString2 s1, unsigned int n) {

    if (n > SZ) {
        cout << "You reached the limit. n value set to SZ - 1.\n";
        n = SZ - 1;
    }
    else if (n > strlen(s1)) {
        cout << "You reached the limit. n value set to strlen(s1).\n";
        n = strlen(s1) - 1;
    }

    int i;
    int len = strlen(s1);
    for (i = 0; i < n; i++) {
        str[i] = s1[len-n+i];
    }
    str[i] = '\0';

    return PString2(str);

}


int main() {

    // old tests
    PString s1 = "This is a very long string which is probably "
        "no, certainly--going to exceed the limit set by SZ.";
    cout << "s1="; s1.display(); cout << endl;

    PString s2 = "This is a short string.";
    cout << "s2="; s2.display(); cout << endl;
    cout << endl;

    // new tests
    PString2 s3 = "This is test string.";
    PString2 text1 = "text";
    PString2 text2 = "this is Text (version 2)";
    PString2 text3 = "this is another TEXT";

    PString2 test = s3.left(text1, 4);
    s3.display(); cout << endl;
    test.display(); cout << endl;
    s3.mid(text2, 8, 4);    s3.display(); cout << endl;
    s3.right(text3, 4);     s3.display(); cout << endl;

    return 0;

}
