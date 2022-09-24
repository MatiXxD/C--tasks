#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


class String {

private:
    static const int SZ = 80;
    char str[SZ];

public:
    String() {
        strcpy(str, "");
    }

    String(const char s[]) {
        strcpy(str, s);
    }

    void display() const {
        cout << str;
    }

    String operator += (String ss) {

        if (strlen(str) + strlen(ss.str) < SZ){
            strcat(str, ss.str);
        }
        else{
            cout << "\nString overflow"; exit(1);
        }

        return String(str);
    }

};


int main(){

    String s1 = "\nMerry Christmas!  ";
    String s2 = "Happy new year!";

    s1.display(); cout << endl;
    s2.display(); cout << endl;

    cout << "\nNew str1: ";
    s1 += s2;
    s1.display();
    cout << endl;

    return 0;

}
