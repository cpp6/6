#include<iostream>

#include<string>

#include<cstring>

using namespace std;

struct node {

int prn;

string name;

node* next;

};

node *temp,*temp1,*temp2;

class pinclub {

public:

node *head,*tail,*nnode;

pinclub() {

    head=tail=NULL;

}

void create();

void display();

void deletepresident();

void deletesecretary();

void deletemember();

void count();

};

void pinclub::create() {

char m;

do {

    nnode=new node;

    nnode->next=NULL;

    cout<<endl<<"Enter prn number: ";

    cin>>nnode->prn;

    cout<<endl<<"Enter name of user: ";

    cin>>nnode->name;

    if(head==NULL) {

        head=tail=nnode;

    } else {

        tail->next=nnode;

        tail=nnode;

    }

    cout<<endl<<"Do you want to continue(y or n): ";

    cin>>m;

} while(m=='y');

display();

}

void pinclub::display() {

cout<<endl<<" YOUR UPDATED CLUB DATA IS: "<<endl;

if(head==NULL) {

    cout<<endl<<"club is empty";

} else {

    cout<<"\n PRN NO.\t NAME"<<endl;  

    temp=head;

    while(temp!=NULL) {

        cout<<endl<<temp->prn<<"           " <<temp->name;

        temp=temp->next;

    }

}

}

void pinclub::deletepresident() {

string ch;

cout<<endl<<"Do you want to delete president(y or n): ";

cin>>ch;

if(ch=="y" && head!=NULL) {

    temp=head;

    cout<<endl<<"you deleted head= "<<temp->name<<"          "<<temp->prn<<" "; 

    head=temp->next;

    delete temp;

    display();

}

}

void pinclub::deletesecretary() {

string ch;

cout<<endl<<"Do you want to delete scretary(y or n):";

cin>>ch;

if(ch=="y" && head!=NULL && tail!=NULL) {

    temp=head;

    while(temp->next!=tail) {

        temp=temp->next;

    }

    cout<<endl<<"you deleted secretary= "<<tail->name<<"       " <<tail->prn<<" "; 

    delete tail;

    tail=temp;

    tail->next=NULL;

    display();

}

}

void pinclub::deletemember() {

string ch;

string key;

cout<<endl<<"Do you want to delete member (y or n):";

cin>>ch;

if(ch=="y") {

    cout<<endl<<"Enter the member name that you want to delete: ";

    cin>>key;

    temp=head;

    while(temp->next!=NULL && (temp->next->name)!=key) {

        temp=temp->next;

    }

    if(temp->next==NULL) return;

    temp1=temp->next;

    temp2=temp1->next;

    cout<<endl<<"you deleted intermegiate member= "<<temp1->name<<" "<< temp1->prn<<" "; 

    delete temp1;

    temp->next=temp2;

    display();

}

}

void pinclub::count() {

string ch;

cout<<endl<<"Do you want to count club members (y or n)";

cin>>ch;

if(ch=="y") 
  {

    int c=0;

    temp=head;

    while(temp!=NULL)
    {

        c++;

        temp=temp->next;

    }

    cout<<"total member of club are: "<<c;

}
}
int main ()
{

pinclub l1;

cout<<endl<<"Welcome to club"<<endl;

l1.create();
l1.deletepresident();
l1.deletesecretary();
l1.deletemember();
l1.count();
l1.display();

return 0;

}
