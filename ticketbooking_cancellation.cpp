#include <iostream>
using namespace std;

struct node {
    node* Array[10];
    int status;
    int seat_no;
    node* prev;
    node* next;
};

class DLL {
public:
    node* Array[10];
    node* head;
    node* tail;

    void creation();
    void display();
    void booking();
    void cancellation();
};

void DLL::creation() {
    for (int j = 1; j < 11; j++) {
        Array[j] = NULL;
        for (int i = 1; i < 8; i++) {
            node* nnode = new node;
            nnode->status = 0;
            nnode->prev = NULL;
            nnode->next = NULL;
            nnode->seat_no = i;

            if (Array[j] == NULL) {
                Array[j] = nnode;
                tail = nnode;
            } else {
                tail->next = nnode;
                nnode->prev = tail;
                tail = nnode;
            }
        }
    }
}

void DLL::display() {
    cout << "\nAvailable seats are:\n";
    for (int j = 1; j < 11; j++) {
        node* temp = Array[j];
        cout << "\nRow no " << j << ":\n";
        while (temp != NULL) {
            if (temp->status == 0)
                cout << "Seat " << temp->seat_no <<endl;
            temp = temp->next;
        }
        cout << endl;
    }
}

void DLL::booking() {
    char ch;
    cout << "\nAvailable seats before booking:\n";
    display();

    do {
        int row, seat;
        cout << "Enter row no for booking: ";
        cin >> row;
        cout << "Enter seat no for booking: ";
        cin >> seat;

        node* temp = Array[row];
        while (temp != NULL && temp->seat_no != seat)
            temp = temp->next;

        if (temp == NULL)
            cout << "Invalid seat number.\n";
        else if (temp->status == 1)
            cout << "Seat already booked!\n";
        else {
            temp->status = 1;
            cout << "\nSeat " << temp->seat_no << " in row " << row << " booked successfully!\n";
        }

        cout << "\nDo you want to book more seats (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

void DLL::cancellation() {
    char ch;
    do {
        int row, seat;
        cout << "\nEnter row no for cancellation: ";
        cin >> row;
        cout << "Enter seat no for cancellation: ";
        cin >> seat;

        node* temp = Array[row];
        while (temp != NULL && temp->seat_no != seat)
            temp = temp->next;

        if (temp == NULL) {
            cout << "\nInvalid seat number.\n";
        } else if (temp->status == 1) {
            temp->status = 0;
            cout << "\nYour seat " << temp->seat_no << " from row " << row << " is cancelled.\n";
        } else {
            cout << "\nThis seat was not booked.\n";
        }

        cout << "\nDo you want to cancel any more seats (y/n): ";
        cin >> ch;

    } while (ch == 'y');
}

int main() {
    DLL l1;
    l1.creation();
    l1.booking();
    l1.display();
    l1.cancellation();
    l1.display();
    return 0;
}
