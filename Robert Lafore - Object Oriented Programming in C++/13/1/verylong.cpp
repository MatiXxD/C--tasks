#include "verylong.h"        



void verylong::putvl() const {

    char temp[SZ];
    strcpy(temp, vlstr);              
    cout << _strrev(temp);   

}                                  

void verylong::getvl() {

    cin >> vlstr;                  
    vlen = strlen(vlstr);          
    _strrev(vlstr);        

}

verylong verylong::operator + (const verylong v) {

    char temp[SZ];
    int j;
    int maxlen = (vlen > v.vlen) ? vlen : v.vlen;
    int carry = 0;        
    for (j = 0; j < maxlen; j++) {
        int d1 = (j > vlen - 1) ? 0 : vlstr[j] - '0'; 
        int d2 = (j > v.vlen - 1) ? 0 : v.vlstr[j] - '0'; 
        int digitsum = d1 + d2 + carry;       
        if (digitsum >= 10) {
            digitsum -= 10; carry = 1;
        }  
        else                             
            carry = 0;                    
        temp[j] = digitsum + '0';        
    }

    if (carry == 1)                       
        temp[j++] = '1';             
    temp[j] = '\0';       

    return verylong(temp);             

}

verylong verylong::operator * (const verylong v) {     

    verylong pprod;                    
    verylong tempsum;                   
    for (int j = 0; j < v.vlen; j++) {
        int digit = v.vlstr[j] - '0';    
        pprod = multdigit(digit);        
        for (int k = 0; k < j; k++)       
            pprod = mult10(pprod);        
        tempsum = tempsum + pprod;      
    }

    return tempsum;       

}

verylong verylong::mult10(const verylong v) const {    

    char temp[SZ];
    for (int j = v.vlen - 1; j >= 0; j--)     
        temp[j + 1] = v.vlstr[j];       
    temp[0] = '0';                      
    temp[v.vlen + 1] = '\0';         

    return verylong(temp);             

}

verylong verylong::multdigit(const int d2) const {                

    char temp[SZ];                     
    int j, carry = 0;
    for (j = 0; j < vlen; j++) {                               
        int d1 = vlstr[j] - '0';          
        int digitprod = d1 * d2;        
        digitprod += carry;              
        if (digitprod >= 10) {
            carry = digitprod / 10;        
            digitprod -= carry * 10;     
        }
        else
            carry = 0;                    
        temp[j] = digitprod + '0';         
    }
    if (carry != 0)                     
        temp[j++] = carry + '0';           
    temp[j] = '\0';            

    return verylong(temp);      

}

//////////////////////////////////////////////////////////////////////////////////////////
// Subtraction

bool verylong::cmp(const verylong v) const {

    int maxLen;
    if (vlen > v.vlen) return true;
    else if (vlen < v.vlen) return false;

    for (int i = vlen- 1; i >= 0; i--) {
        if (vlstr[i] < v.vlstr[i]) return false;
        else if (vlstr[i] > v.vlstr[i]) return true;
    }

    return true;

}

verylong verylong::operator - (const verylong v) {

    char temp[SZ];
    int maxLen = (vlen > v.vlen) ? vlen : v.vlen;
    bool isMax = this->cmp(v);
    
    int res, j;
    int carry = 0;
    for (j = 0; j < maxLen; j++) {

        int d1 = (j > vlen - 1) ? 0 : vlstr[j] - '0';
        int d2 = (j > v.vlen - 1) ? 0 : v.vlstr[j] - '0';

        if (isMax)  res = (d1 - carry) - d2;
        else        res = (d2 - carry) - d1;
        
        if (res < 0) {
            res += 10; carry = 1;
        }
        else {
            carry = 0;
        }
        
        temp[j] = res + '0';

    }

    if (!isMax) {
        temp[j++] = '-';
    }
    temp[j] = '\0';

    for (int i = j - 1; i > 0; i--) {
        if (temp[i] == '0') temp[i] = '\0';
        else if (temp[i] != '0') break;
    }

    return verylong(temp);

}

//////////////////////////////////////////////////////////////////////////////////////////
// Division (work as division for two integers)

verylong verylong::div10(const verylong v) const {

    char temp[SZ];
    for (int j = v.vlen - 1; j > 0; j--)
        temp[j - 1] = v.vlstr[j];
    temp[v.vlen-1] = '\0';

    return verylong(temp);

}

verylong verylong::operator / (const verylong v) {

    if (!this->cmp(v)) return verylong("0");


    char temp[SZ];
    verylong remainder(*this);
    verylong div(v);
    verylong testVal;
    
    int n = 0;
    while (remainder.cmp(mult10(div)) && strcmp(vlstr, mult10(div).vlstr)) {
        div = mult10(div);
        n++;
    }

    for (int i = 0; i <= n; i++) {

        int digit = 0;
        verylong tempDiv(div);
        while (remainder.cmp(tempDiv) && strcmp(vlstr, tempDiv.vlstr)) {
            tempDiv = div.multdigit(digit+2);
            digit++;
        }
        if (digit) testVal = div.multdigit(digit);
        if(digit) remainder = remainder - div.multdigit(digit);
        div = div10(div);

        temp[i] = digit + '0';

    }
    temp[n+1] = '\0';

    return verylong(_strrev(temp));

}