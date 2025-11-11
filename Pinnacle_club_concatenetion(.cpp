#include <iostream>
using namespace std;

struct member {
    int PRN;
    string name;
    member *next;
};

class SLL {
public:
    member *president, *secretary;

    SLL() {
        president = NULL;
        secretary = NULL;
    }

    void create();
    void display();
    void count();
    void concatenate();
};

void SLL::create() {
    char ch;
    do {
        member *nnode = new member;
        cout << "Enter PRN number of new member: ";
        cin >> nnode->PRN;
        cout << "Enter name of new member: ";
        cin >> nnode->name;
        nnode->next = NULL;

        if (president == NULL) {
            president = nnode;
            secretary = nnode;
        } else {
            secretary->next = nnode;
            secretary = nnode;
        }

        cout << "Do you want to add another member? (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

void SLL::display() {
    if (president == NULL) {
        cout << "\nClub is empty.\n";
        return;
    }

    member *temp = president;
    cout << "\nClub Members:\n";
    while (temp != NULL) {
        cout << "PRN: " << temp->PRN << " | Name: " << temp->name << endl;
        temp = temp->next;
    }
}

void SLL::count() {
    int cnt = 0;
    member *temp = president;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    cout << "\nTotal members are : " << cnt << endl;
}



int main() {
    SLL l1, l2;
    char ch;
    cout << "Welcome to Pinnacle Club\n";

    cout << "\n--- Create List 1 ---\n";
    l1.create();
    cout << "\n--- Create List 2 ---\n";
    l2.create();

    cout << "\n---  List 1 ---";
    l1.display();
    cout << "\n--- List 2 ---";
    l2.display();
    cout<<"\n do you want to concatenate list 1 and list 2(y/n) : ";
    cin>>ch;
    if(ch=='y')
    {
    cout << "\n--- After Concatenation list is ---";
    if(l1.secretary!=NULL && l2.president!=NULL) {

    l1.secretary->next=l2.president;

    l1.secretary=l2.secretary;
    }
}

    l1.display();

    l1.count();

    return 0;
}