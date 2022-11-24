#include <iostream>
#include <cstring>
using namespace std;

void bsort(const char**, int);

int main() {

    const char* arrptrs[7] = { "Sunday", "Monday", "Tuesday",
               "Wednesday", "Thursday",
               "Friday", "Saturday" };
    for (int j = 0; j < 7; j++)
        cout << arrptrs[j] << " ";
    cout << endl;

    bsort(arrptrs, 7);
    for (int j = 0; j < 7; j++)
        cout << arrptrs[j] << " ";
    cout << endl;

    return 0;

}

void bsort(const char** days, int n) {

    void order(const char**, const char**);
    int j, k;

    for (j = 0; j < n - 1; j++)
        for (k = j + 1; k < n; k++)
            order(days + j, days + k);
}

void order(const char** s1, const char** s2) {

    if (strcmp(*s1, *s2) > 0) {
        const char* temp = *s1;
        *s1 = *s2;
        *s2 = temp;
    }

}
