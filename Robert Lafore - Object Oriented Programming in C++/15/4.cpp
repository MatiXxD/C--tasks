#include <iostream>
#include <algorithm>
#include <set>


class person {

private:
    std::string lastName;
    std::string firstName;
    long phoneNumber;

public:
    person() : lastName("blank"), firstName("blank"), phoneNumber(0L) { }
    
    person(std::string lana, std::string fina, long pho) : 
        lastName(lana), firstName(fina), phoneNumber(pho) {  }

    void display() const {
        std::cout << std::endl << lastName << ",\t" << firstName
            << "\t\tPhone: " << phoneNumber;
    }

    long get_phone() const {
        return phoneNumber;
    }

    friend bool operator<(const person&, const person&);

}; 

bool operator<(const person& p1, const person& p2) {
    if (p1.lastName == p2.lastName)
        return (p1.firstName < p2.firstName) ? true : false;
    return (p1.lastName < p2.lastName) ? true : false;
}


///////////////////////////////////////////////////////////


class comparePerson {
public:
    bool operator() (const person* ptr1, const person* ptr2) const {
        return *ptr1 < *ptr2;
    }
};


///////////////////////////////////////////////////////////


void printSet(const std::multiset<person*, comparePerson>& mltSet) {

    for (std::multiset<person*, comparePerson>::iterator iter = mltSet.begin();
        iter != mltSet.end(); iter++)
        (*iter)->display();
    std::cout << std::endl;

}

void dltSet(std::multiset<person*, comparePerson>& mltSet) {

    std::multiset<person*, comparePerson>::iterator iter = mltSet.begin();
    while (iter != mltSet.end()){
        delete *iter;
        mltSet.erase(iter++);
    } 

}


int main() {

    std::multiset<person*, comparePerson> mltSet;

    person* ptrP1 = new person("KuangThu", "Bruce", 4157300);
    person* ptrP2 = new person("McDonald", "Stacey", 3327563);
    person* ptrP3 = new person("Deauville", "William", 8435150);
    person* ptrP4 = new person("Wellington", "John", 9207404);
    person* ptrP5 = new person("Bartoski", "Peter", 6946473);
    person* ptrP6 = new person("McDonald", "Amanda", 8435150);
    person* ptrP7 = new person("Fredericks", "Roger", 7049982);
    person* ptrP8 = new person("McDonald", "Stacey", 7764987);

    person* ptrArr[8] = { ptrP1, ptrP2, ptrP3, ptrP4, ptrP5, ptrP6, ptrP7, ptrP8 };
    for (int i = 0; i < 8; i++) mltSet.insert(ptrArr[i]);

    printSet(mltSet);
    dltSet(mltSet);

	return 0;

}