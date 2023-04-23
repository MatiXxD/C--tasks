#include <fstream>
#include <iostream>
#include <typeinfo>
#include <process.h>

const int LEN = 32;
const int MAXEM = 100;

enum employee_type { tmanager, tscientist, tlaborer };
////////////////////////////////////////////////////////////////
class employee {

private:
    char name[LEN];
    unsigned long number;
    static int n;
    static employee* arrap[];

public:
    virtual void getdata() {
        std::cin.ignore(10, '\n');
        std::cout << "   Enter last name: ";    std::cin >> name;
        std::cout << "   Enter number: ";       std::cin >> number;
    }

    virtual void putdata() {
        std::cout << "\n   Name: " << name;
        std::cout << "\n   Number: " << number;
    }

    virtual employee_type get_type();
    static void add();
    static void display();
    static void read();
    static void write();
    static void find();

};

int employee::n;
employee* employee::arrap[MAXEM];

////////////////////////////////////////////////////////////////
//manager class
class manager : public employee {

private:
    char title[LEN];
    double dues;

public:
    void getdata() {
        employee::getdata();
        std::cout << "   Enter title: ";          std::cin >> title;
        std::cout << "   Enter golf club dues: "; std::cin >> dues;
    }

    void putdata() {
        employee::putdata();
        std::cout << "\n   Title: " << title;
        std::cout << "\n   Golf club dues: " << dues;
    }

};


////////////////////////////////////////////////////////////////
//scientist class
class scientist : public employee {

private:
    int pubs;

public:
    void getdata() {
        employee::getdata();
        std::cout << "   Enter number of pubs: "; std::cin >> pubs;
    }

    void putdata() {
        employee::putdata();
        std::cout << "\n   Number of publications: " << pubs;
    }

};


////////////////////////////////////////////////////////////////
//laborer class
class laborer : public employee{

};


////////////////////////////////////////////////////////////////
//add employee to list in memory
void employee::add() {

    char ch;
    std::cout << "'m' to add a manager"
        "\n's' to add a scientist"
        "\n'l' to add a laborer"
        "\nEnter selection: ";

    std::cin >> ch;
    switch (ch) {
    case 'm': arrap[n] = new manager;   break;
    case 's': arrap[n] = new scientist; break;
    case 'l': arrap[n] = new laborer;   break;
    default: std::cout << "\nUnknown employee type\n"; return;
    }

    arrap[n++]->getdata();

}
//--------------------------------------------------------------
//display all employees
void employee::display()
{
    for (int j = 0; j < n; j++) {

        std::cout << (j + 1);
        switch (arrap[j]->get_type()) {
        case tmanager:    std::cout << ". Type: Manager";   break;
        case tscientist:  std::cout << ". Type: Scientist"; break;
        case tlaborer:    std::cout << ". Type: Laborer";   break;
        default: std::cout << ". Unknown type";
        }

        arrap[j]->putdata();
        std::cout << std::endl;

    }

}
//--------------------------------------------------------------
//return the type of this object
employee_type employee::get_type() {

    if (typeid(*this) == typeid(manager))
        return tmanager;
    else if (typeid(*this) == typeid(scientist))
        return tscientist;
    else if (typeid(*this) == typeid(laborer))
        return tlaborer;
    else {
        std::cerr << "\nBad employee type"; exit(1);
    }

    return tmanager;

}
//--------------------------------------------------------------
//write all current memory objects to file
void employee::write() {

    int size;
    std::cout << "Writing " << n << " employees.\n";
    std::ofstream ouf;
    employee_type etype;

    ouf.open("EMPLOY.DAT", std::ios::trunc | std::ios::binary);
    if (!ouf) {
        std::cout << "\nCan't open file\n"; return;
    }

    for (int j = 0; j < n; j++) {

        etype = arrap[j]->get_type();

        ouf.write((char*)&etype, sizeof(etype));
        switch (etype) {
        case tmanager:   size = sizeof(manager); break;
        case tscientist: size = sizeof(scientist); break;
        case tlaborer:   size = sizeof(laborer); break;
        }

        ouf.write((char*)(arrap[j]), size);
        if (!ouf) {
            std::cout << "\nCan't write to file\n"; return;
        }

    }

}
//--------------------------------------------------------------
//read data for all employees from file into memory
void employee::read() {

    int size;
    employee_type etype;
    std::ifstream inf;

    inf.open("EMPLOY.DAT", std::ios::binary);
    if (!inf) {
        std::cout << "\nCan't open file\n"; return;
    }

    n = 0;
    while (true) {

        inf.read((char*)&etype, sizeof(etype));
        if (inf.eof()) break;
        if (!inf) {
            std::cout << "\nCan't read type from file\n"; return;
        }

        switch (etype) {
        case tmanager:
            arrap[n] = new manager;
            size = sizeof(manager);
            break;
        case tscientist:
            arrap[n] = new scientist;
            size = sizeof(scientist);
            break;
        case tlaborer:
            arrap[n] = new laborer;
            size = sizeof(laborer);
            break;
        default: std::cout << "\nUnknown type in file\n"; return;
        }

        inf.read((char*)arrap[n], size);
        if (!inf) {
            std::cout << "\nCan't read data from file\n"; return;
        }

        n++;

    }

    std::cout << "Reading " << n << " employees\n";

}
//--------------------------------------------------------------
//find person in data and print info
void employee::find() {

    int id;
    std::cout << "Enter id: "; std::cin >> id;

    int size;
    employee* empl = NULL;
    employee_type etype;
    std::ifstream inf;

    inf.open("EMPLOY.DAT", std::ios::binary);
    if (!inf) {
        std::cout << "\nCan't open file\n"; return;
    }

    n = 0; bool flag = false;
    while (true) {

        inf.read((char*)&etype, sizeof(etype));
        if (inf.eof()) break;
        if (!inf) {
            std::cout << "\nCan't read type from file\n"; return;
        }

        switch (etype) {
        case tmanager:
            empl = new manager;
            size = sizeof(manager);
            break;
        case tscientist:
            empl = new manager;
            size = sizeof(scientist);
            break;
        case tlaborer:
            empl = new manager;
            size = sizeof(laborer);
            break;
        default: std::cout << "\nUnknown type in file\n"; return;
        }

        inf.read((char*)empl, size);
        if (!inf) {
            std::cout << "\nCan't read data from file\n"; return;
        }

        n++;
        if (empl->number == id) {
            std::cout << "Employee with id " << id << " was found at " << n << " position.\n";
            switch (empl->get_type()) {
            case tmanager:    std::cout << "Type: Manager";   break;
            case tscientist:  std::cout << "Type: Scientist"; break;
            case tlaborer:    std::cout << "Type: Laborer";   break;
            }
            empl->putdata();
            std::cout << std::endl;
            flag = true; break;
        }

    }

    if (!flag) std::cout << "Employee with id " << id << " wasn't found.";

    if (empl != NULL) {
        delete empl;
    }

}





int main() {

    int id;
    char ch;

    while (true) {

        std::cout << "'a' -- add data for an employee"
            "\n'd' -- display data for all employees"
            "\n'w' -- write all employee data to file"
            "\n'r' -- read all employee data from file"
            "\n'f' -- find person in file"
            "\n'x' -- exit"
            "\nEnter selection: ";
        std::cin >> ch;

        switch (ch) {
        case 'a':
            employee::add(); break;
        case 'd':
            employee::display(); break;
        case 'w':
            employee::write(); break;
        case 'r':
            employee::read(); break;
        case 'f':
            employee::find(); break;
        case 'x': exit(0);
        default: std::cout << "\nUnknown command";
        }

    }

    return 0;

}
