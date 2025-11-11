#include <iostream>
#include <cstring>
using namespace std;

struct database
{
    char name[10];
    char cname[10];
    char dname[10];
    int cont_no;
    int tel_no;
    int mob_no;
};

int main()
{
    int n;
    char ch;
    database Qhash[10];
    cout << "How many data do you want to store: ";
    cin >> n;

    for (int i = 0; i < 10; i++)  
    {
        strcpy(Qhash[i].cname, "none");
        Qhash[i].mob_no = -1;
    }
    cout << endl;

    cout << "***Empty Hash Table***" << endl;
    cout << "Name Telephone no" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << Qhash[i].cname << "   " << Qhash[i].mob_no << endl;
    }
    cout << endl;
    
    
    char Tname[10];
    int tel;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter client's Name: ";
        cin >> Tname;

        cout << "Enter Telephone No.: ";
        cin >> tel;

        int total = 0;
        for (int j = 0; Tname[j] != '\0'; j++)
        {
            total += Tname[j];
        }
        int h = total%10;
        if (Qhash[h].mob_no == -1)
        {
            strcpy(Qhash[h].cname, Tname);
            Qhash[h].mob_no = tel;
        }
        else
        {
            for (int i = 1; i < 10; i++)
            {
                int nh = (h + i*i) % 10;
                if (Qhash[nh].mob_no == -1)
                {
                    strcpy(Qhash[nh].cname, Tname);
                    Qhash[nh].mob_no = tel;
                    break;
                }
            }
        }
    }
    
    cout << endl;

    cout << "***Quadratic Probing Hash Table***" << endl;
    cout << "Name Telephone no" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << Qhash[i].cname << "   " << Qhash[i].mob_no << endl;
    }
    cout << endl;
    
    do{
    char Sname[10];
    cout << "\nEnter name to search: ";
    cin >> Sname;

    int total = 0;
    for (int j = 0; Sname[j] != '\0'; j++)
    {
        total += Sname[j];
    }
    int h = total % 10;
    // Quadratic Probing Search
    int found = 0;
    for (int i = 0; i < 10; i++)
    {
        int nh = (h + i*i) % 10;
        if (strcmp(Qhash[nh].cname, Sname) == 0)
        {
            cout << "Found in Quadratic Probing at index " << nh << ": " << Qhash[nh].cname << " " << Qhash[nh].mob_no << endl;
            found = 1;
            break;
        }
    }
    if (found==0) cout << "Not found in Quadratic Probing.\n";
    cout<<"DO YOU WANT TO CONTINUE(y/n)";
    cin>>ch;
    }
    while(ch=='y');

    return 0;
}