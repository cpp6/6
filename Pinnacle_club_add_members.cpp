#include <iostream>
#include <cstring>
using namespace std;
struct member
{
    int PRN;
    string name;
    member *next;
};
char ch;
int tempPRN;
string tempname;
member* nnode;
member* temp;
int key;
class SLL
{
    public : member *president , *secretory;
    SLL()
    {
        president=NULL;
        secretory=NULL;
    }
    void display();
    void create();
    void delet();
    void count();
    void add();
    
};
void SLL :: create()
{
        member *nnode = new member;
        cout<<"enter PRN no of new member"<<endl;
        cin>>nnode -> PRN;
        cout<<"enter name of new member"<<endl;
        cin>> nnode -> name;
        nnode -> next =NULL;
        if (president == NULL) {  
            // First node
            president = nnode;
            secretory = nnode;
        } 
        else {
            secretory->next = nnode;  // link new member
            secretory = nnode;        // update secretary
        }
}
void SLL :: display()
{
    temp = president;
    if(president==NULL)
    {
        cout<<"club is empty"<<endl;
    
    }
    else
    {
     while (temp != NULL) {
        cout << "PRN: " << temp->PRN << " | Name: " << temp->name << endl;
        temp = temp->next;
     }
    }
 }

char ans;
char h,t,m;
void SLL :: add(){
    do{
        cout<<"where you want to store? h/t/m";
        cin>>ans;
        nnode=new member;
        nnode->next=NULL;
        cout<<"enter PRN no of new member";
        cin>>nnode->PRN;
        cout<<"enter name of new member";
        cin>>nnode->name;
        if(ans=='h'){
        nnode->next=president;
        president=nnode;
        }
        if(ans=='t'){
        secretory->next=nnode;
        secretory=nnode;
        }
        if(ans=='m'){
        cout<<"after which PRN you want to insert";
        cin>>key;
        temp=president;
        while(temp->PRN!=key)
        {
            temp=temp->next;
        }
        nnode->next=temp->next;
        temp->next=nnode;
        }
        cout<<"do you want to continue?y/n";
        cin>>ch;
    }
    while(ch=='y');
    
}
void SLL :: count()
{
    int count=0;
    temp=president;
    while(temp!=NULL)
    {
        count++;
    }
    cout<<"total members are : "<<count;
}
int main()
{
    SLL l1,l2;
    cout<<"welcome in pinnacle club"<<endl;
    l1.create();
    l1.display();
    l1.add();
    l1.display();
    l1.count();
    
    return 0;
}