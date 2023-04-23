#include <iostream>
#include <fstream>
#include <string>
using namespace std;



////////////////////////////////////////////////////////////////

struct link {
    int data;
    link* next;
};

////////////////////////////////////////////////////////////////

class Linklist {

private:
    link* first;

public:
    Linklist() {
        first = NULL;
    }
    ~Linklist() {
        deleteList();
    }

    void additem(int d);
    void display();
    void deleteList();
    void writeData(std::string fileName);
    void readData(std::string fileName);

};

void Linklist::additem(int d) {

    link* newlink = new link;
    newlink->data = d;
    newlink->next = first;
    first = newlink;

}

void Linklist::display() {

    int i = 0;
    link* current = first;
    while (current != NULL) {
        cout << current->data << ' '; i++;
        if (i % 10 == 0) std::cout << std::endl;
        current = current->next;
    }

    if (i % 10) std::cout << std::endl;

}

void Linklist::deleteList() {

    link* temp;

    while (first) {
        temp = first;
        first = first->next;
        delete temp;
    }

}

void Linklist::writeData(std::string fileName) {

    std::ofstream fout(fileName, std::ios::out);

    link* temp = first;

    if (temp) {
        fout << temp->data;
        temp = temp->next;
    }
    while (temp && (fout << '\n')) {
        fout << temp->data;
        temp = temp->next;
    }

    fout.close();

}

void Linklist::readData(std::string fileName) {

    std::ifstream fin(fileName, std::ios::in);

    if (first == NULL) {
        int data;
        while (!fin.eof()) {
            fin >> data;
            this->additem(data);
        }
    }
    else {
        std::cout << "Delete your list before copy.\n";
    }

    fin.close();

}

////////////////////////////////////////////////////////////////



int main() {

    Linklist list;

    int option;
    std::cout << "Enter what you want to do:\n" <<
        "1) Add item to list.\n" <<
        "2) Delete list.\n" <<
        "3) Show list.\n" <<
        "4) Write list to file.\n" <<
        "5) Read list from file.\n" <<
        "0) Exit.\n\n";
    std::cin >> option;

    while (option) {

        int data;
        std::string name;

        switch (option) {
        case 1:
            std::cout << "Enter data: "; std::cin >> data;
            list.additem(data); break;

        case 2:
            list.deleteList(); break;

        case 3:
            list.display(); break;

        case 4:
            std::cout << "Enter file name: "; std::cin >> name;
            list.writeData(name); break;

        case 5:
            std::cout << "Enter file name: "; std::cin >> name;
            list.readData(name); break;

        default:
            std::cout << "Wrong option.\n";

        }

        std::cout << "Enter what you want to do:\n" <<
            "1) Add item to list.\n" <<
            "2) Delete list.\n" <<
            "3) Show list.\n" <<
            "4) Write list to file.\n" <<
            "5) Read list from file.\n" <<
            "0) Exit.\n\n";
        std::cin >> option;

    }

    return 0;

}
