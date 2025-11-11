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
    database Hash[10];
    cout << "How many data do you want to store: ";
    cin >> n;

    for (int i = 0; i < 10; i++)  
    {
        strcpy(Hash[i].name, "none");
        Hash[i].tel_no = -1;
    }
    cout << endl;

    cout << "***Empty Hash Table***" << endl;
    cout << "Name Telephone no" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << Hash[i].name << "   " << Hash[i].tel_no << endl;
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
       

        
        if (Hash[h].tel_no == -1)
        {
            strcpy(Hash[h].name, Tname);
            Hash[h].tel_no = tel;
        }
        else
        {
            for(int i = 1; i < 10; i++)
            {
                int nh = (h + i) % 10;
                if (Hash[nh].tel_no == -1)
                {
                    strcpy(Hash[nh].name, Tname);
                    Hash[nh].tel_no = tel;
                    break;
                }
            }
        }
    }
    
    cout << endl;
    cout << "***Linear Probing Hash Table***" << endl;
    cout << "Name Telephone no" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << Hash[i].name << "   " << Hash[i].tel_no << endl;
    }
    cout << endl;

    
}