#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class String {

private:
    char* str;

public:
    String(const char* s) {
        int length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    ~String() {
        cout << "Deleting str\n";
        delete[] str;
    }

    void display() {
        cout << str << endl;
    }

    void upit() {
        for (int i = 0; i < strlen(str); i++)
            str[i] = toupper(str[i]);
    }

};

int main() {

    String s1 = "Who knows nothing doubts nothing.";
    s1.upit();
    cout << "s1=";
    s1.display();

    return 0;

}
