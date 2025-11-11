#include <iostream>
using namespace std;
class queu
{
	public :
	int front,rear;
	int jobqueue[20];
	int max=10;
	queu()
	{
		front=0;
		rear=-1;
		max=10;
	}
	int Isempty();
	int Isfull();
	void enqueue();
	void dequeue();
	void display();
};
int queu::Isempty()
{
	if(front>rear)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
int queu::Isfull()
{
	if(rear==max-1)
	{
		return 1 ;
	}
	else
	{
		return 0;
	}
}
void queu::dequeue()
{
	char ch;
    do
    {
	if(!Isempty())
	{
		cout<<"\njob no"<<jobqueue[front]<<"  "<<"is deleted"<<endl;
		if(front==rear)
		{
			front=0;
			rear=-1;
		}
		else
		{
			front++;
		}
	}
	else
	{
		cout<<"\nstack underflow";
	}
	cout<<"do you want to delete more elements(y/n) : "<<endl;
	cin>>ch;
    }
    while(ch=='y');
}
void queu::enqueue ()
{
    char ch;
    int e;
    do
    {
        cout<<"enter element for inserting into queue : "<<endl;
        cin>>e;
        if(!Isfull())
        {
            rear++;
            jobqueue[rear]=e;
        }
        else
        {
            cout<<"queue overflow";
        }
        cout<<"do you want to add more element(y/n) : "<<endl;
        cin>>ch;
    }
    while(ch=='y');
}
void queu::display()
{
    if(!Isempty())
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<jobqueue[i]<<" ";
        }
    }
    else
    {
        cout<<"queue is empty";
    }
}
int main()
{
     
     queu q1;
     q1.enqueue();
     q1.display();
     q1.dequeue();
     q1.display();
     
}