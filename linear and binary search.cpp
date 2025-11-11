//Linear Search
#include<iostream>
#include<algorithm>
using namespace std;

void linearSearch()
{
    int i,key,n;
    char ans1,ch;

    cout<<"How many students were present for the program?";
    cin>>n;
    int roll_no[n];
    cout<<"Enter the roll  number of students:"<<endl;

    for(i=0;i<n;i++)
        {
            
            cin>>roll_no[i];
        }
        cout<<"The present roll number of students are:"<<endl;
        for(i=0;i<n;i++)
        {
            cout<<roll_no[i]<<endl;
        }
        cout<<"Do you want to check the presence of any student (y/n)?";
        cin>>ans1;
        if(ans1=='y')
        {
            do
            {
                cout<<"Enter the roll number of student whose presence do you want to check:";
                cin>>key;   
            
                for(i=0;i<n;i++)
               {
                if(roll_no[i]==key) 
                {
                    cout<<"This roll number was present for the program.";
                    break;
                }
            }
               if(roll_no[i]!=key)
                {
                cout<<"This roll number was Absent for the program.";
                }
            
            cout<<"\nDo you want to continue for another roll number (y/n)?";
            cin>>ch;
            }while(ch=='y');
        }
         
    else
       {
        cout<<"Thank You!";
       }
}
//binary Search

void binarySearch()
{   
    int key,n,i;
    char ch;
    cout << "How many students were present for the program?" << endl;
    cin >> n;

    int student[n]; 

    cout << "Enter the roll number of students :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> student[i]; 
    }
    cout<<"The roll numbers in sorted order is:"<<endl;
    sort(student,student+n);
    for (int i = 0; i < n; i++)
    {
        cout<<student[i]<<endl; 
        cout<<endl;
    }
    do
    {
        int s = 0, e = n - 1;
        bool match = false;

        cout << "Enter the roll number of the student whose presence you want to check: ";
        cin >> key;

        while (s <= e)
        {
            int mid = s + (e - s) / 2; 

            if (student[mid] == key)
            {
                match = true;
                break;
            }
            else if (student[mid] < key)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        if (match==true)
        {
            cout << "This roll number was present in the program." << endl;
        }
        else
        {
            cout << "This roll number was absent for the program." << endl;
        }

        cout << "Do you want to continue checking for another roll number? (y/n): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');


}
int main(){
    
    int choice;
    do
    {
    
    cout << "\nChoose the search method:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice)
    {
    case 1:{
        linearSearch();
        break;}
    case 2:{
        binarySearch();
        break;}
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
    cout << "\nThank you for using the program!" << endl;
} while (choice == 1 || choice == 2);
    return 0;
}

