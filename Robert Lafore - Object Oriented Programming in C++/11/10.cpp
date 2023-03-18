#include <iostream>
using namespace std;

struct link {

    int data;
    link* next;

};

class linklist {

private:
    int size;
    link* first;

public:
    linklist() : size(0), first(NULL) { }
    linklist(linklist&);
    ~linklist();

    linklist& operator = (linklist&);

    void additem(int d);
    void display();


};

linklist::linklist(linklist& l) : first(NULL), size(0) {

    link* temp;
    first = NULL;

    for (int j = 0; j < l.size; j++) {
        temp = l.first;
        for (int i = 0; i < l.size - j - 1; i++)
            temp = temp->next;
        additem(temp->data);
    }

}

linklist::~linklist() {

    link* l = first;
    while (l != NULL) {
        cout << "Deleting data: " << l->data << endl;
        link* temp = l;
        l = l->next;
        delete temp;
    }

    first = NULL;
    size = 0;

}

linklist& linklist::operator = (linklist& l) {

    if (this == &l) return *this;
    this->~linklist();

    link* temp;
    first = NULL;
    for (int j = 0; j < l.size; j++) {
        temp = l.first;
        for (int i = 0; i < l.size - j - 1; i++)
            temp = temp->next;
        additem(temp->data);
    }

    return *this;

}

void linklist::additem(int d) {

    link* newlink = new link;
    newlink->data = d;
    newlink->next = first;
    first = newlink;
    size++;

}

void linklist::display() {

    link* current = first;
    while (current != NULL) {
        cout << current->data << endl;
        current = current->next;
    }

}


int main() {

    linklist* l1 = new linklist;
    l1->additem(25);
    l1->additem(36);
    l1->additem(49);
    l1->additem(64);
    l1->display(); cout << endl;

    linklist* l2 = new linklist(*l1);
    l2->display(); cout << endl;
    l1->display(); cout << endl;

    linklist l3;
    l3 = *l1;
    l3.display(); cout << endl;
    l1->display(); cout << endl;

    delete l1;
    l2->display(); cout << endl;
    l3.display(); cout << endl;

    return 0;

}
