#include <iostream>
using namespace std;

struct link {

    int data;
    link* next;

};

class linklist {

private:
    link* first;

public:
    linklist() {
        first = NULL;
    }

    ~linklist();
    void additem(int d);
    void display();

};

linklist::~linklist() {

    link* l = first;
    while (l != NULL) {
        cout << "Deleting data: " << l->data << endl;
        link* temp = l;
        l = l->next;
        delete temp;
    }

    first = NULL;

}

void linklist::additem(int d) {

    link* newlink = new link;
    newlink->data = d;
    newlink->next = first;
    first = newlink;

}

void linklist::display() {

    link* current = first;
    while (current != NULL) {
        cout << current->data << endl;
        current = current->next;
    }

}


int main() {

    linklist li;
    li.additem(25);
    li.additem(36);
    li.additem(49);
    li.additem(64);

    li.display(); cout << endl;

    return 0;

}
