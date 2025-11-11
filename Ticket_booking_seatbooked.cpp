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
};

void DLL::creation() {
    for(int j=1;j<11;j++)
    {  
        Array[j] = NULL;
       // tail = NULL;
        for(int i=1;i<8;i++)
        {
            node* nnode = new node;
            nnode->status = 0;
            nnode->prev = NULL;
            nnode->next = NULL;
            nnode->seat_no=i;
            
            if (Array[j] == NULL) {
                Array[j]=nnode;
                tail = nnode;
            
            } 
            else {
            	//cout<<"\n linking is done ben"<<tail->seat_no<<" and"<<nnode->seat_no;
                tail->next = nnode;
                nnode->prev = tail;
                tail = nnode;
             }
        }
      
    }
}

void DLL::display() {
    cout<<"\n Available seats are :";
    for(int j=1;j<11;j++)
     {
        node*temp;
        temp=Array[j];
        cout<<"\n row no "<<j<<":"<<endl;
        while(temp!=NULL)
        {   
            if(temp->status==0)
            {
            cout << "seat " <<temp->seat_no<< " status: " << temp->status << endl;
            }
            temp = temp->next;
        }
        cout<<endl;
    }
}
void DLL::booking()
{
    char ch;
	cout<<"\n Available seats are :";
	display();
	do
	{
    int row,seat;
    cout<<"enter row no";
    cin>>row;
    cout<<"enter seat no";
    cin>>seat;
    node *temp=Array[row];
    while(temp->seat_no!=seat)
    {
        temp=temp->next;
        
    }
    
    temp->status=1;
    cout<<"\ncongratulations!!! you booked seat"<<temp->seat_no<<"from row"<<row;
    cout<<"\n do you want to book more seats(y/n) : ";
    cin>>ch;
	}  
	while (ch=='y');
       
}
int main() {
    DLL l1;
    l1.creation();
    l1.booking();
    l1.display();
    return 0;
}