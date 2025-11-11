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
    database Dhash[10];
    
    cout << "How many data do you want to store: ";
    cin >> n;

    for (int i = 0; i < 10; i++)  
    {
        strcpy(Dhash[i].dname, "none");
        Dhash[i].cont_no = -1;
    }
    cout << endl;

    cout << "***Empty Hash Table***" << endl;
    cout << "Name Telephone no" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << Dhash[i].dname << "   " << Dhash[i].cont_no << endl;
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
        int h = total % 10;
        if (Dhash[h].cont_no == -1)
        {
            strcpy(Dhash[h].dname, Tname);
            Dhash[h].cont_no = tel;
        }
        else
        {
            int h2 = 7 - (total % 7);
            for(int i = 1; i < 10; i++)
            {
                
                int nh = (h + (i * h2)) % 10;
                if (Dhash[nh].cont_no == -1)
                {
                    strcpy(Dhash[nh].dname, Tname);
                    Dhash[nh].cont_no = tel;
                    break;
                }
            }
        }
    }
    
    cout << endl;
    cout << "***Double Probing Hash Table***" << endl;
    cout << "Name Telephone no" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << Dhash[i].dname << "   " << Dhash[i].cont_no << endl;
    }
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
    //  Double Hashing Search
    int h2 = 7 - (total % 7);
    int found = 0;
    for (int i = 0; i < 10; i++)
    {
        int nh = (h + i * h2) % 10;
        if (strcmp(Dhash[nh].dname,Sname) == 0)
        {
           cout << "Found in Double Hashing at index " << nh << ": " << Dhash[nh].dname << " " << Dhash[nh].cont_no << endl;
           found = 1;
           break;
        }
    }
    if (found==0) cout << "Not found in Double Hashing.\n";
    cout<<"DO YOU WANT TO CONTINUE(y/n)";
    cin>>ch;
    }
    while(ch=='y');

    return 0;
}