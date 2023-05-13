#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <string.h>        
#include <stdlib.h>     
using namespace std;

const int SZ = 1000;


class verylong{

private:
    char vlstr[SZ];      
    int vlen;             
    verylong multdigit(const int) const;  
    verylong mult10(const verylong) const;
    verylong div10(const verylong) const;
    bool cmp(const verylong) const;

public:
    verylong() : vlen(0) {
        vlstr[0] = '\0';
    }

    verylong(const char s[SZ]) {
        strcpy(vlstr, s); vlen = strlen(s);
    }   

    verylong(string str) {
        vlen = str.length();
        for (int i = 0; i < vlen; i++) {
            vlstr[i] = str[vlen - 1 - i];
        }
    }

    verylong(const unsigned long n) {   
        _ltoa(n, vlstr, 10);        
        _strrev(vlstr);                
        vlen = strlen(vlstr);         
    }

    verylong(const verylong& v) {
        strcpy(vlstr, v.vlstr);
        vlen = v.vlen;
        vlstr[vlen] = '\0';
    }

    void putvl() const;              
    void getvl();    

    verylong operator + (const verylong); 
    verylong operator * (const verylong); 
    verylong operator - (const verylong);
    verylong operator / (const verylong);

};