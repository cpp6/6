#include <iostream>
using namespace std;

int main() {
    int n;
    cout << " how many students for selection sort: ";
    cin >> n;
    float s[n];
    cout << "Enter percent of students\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter percentage of student " << i+1 << ": ";
        cin >> s[i];
    }

    // display for checking
    cout<<"\n array of percentage is : ";
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }

    for (int pass = 0; pass < n-1; pass++) {
        int minI = pass;
        float min = s[pass];
        int comp = 0;
        for (int j = pass+1; j < n; j++) {
            comp++;
            if (s[j] < s[minI]) {
                minI = j;
                min = s[j];
            }
        }
        // swapping
    
        float temp = s[pass];
        s[pass] = s[minI];
        s[minI] = temp;
        
        cout << "\n Pass " << pass << " Comparisons: " << comp << "  Array: ";
        for(int i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
    }
    cout<<"\n top 5 scores of students : "<<endl;
    for (int i = n-1; i > n-6; i--)
    {  
        // for displaying top 5 scores
        cout << s[i] << " "<<endl;
    }
}