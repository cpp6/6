#include <iostream>
#include <algorithm> 
using namespace std;

bool linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return true;
    }
    return false;
}

bool binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return true;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    int roll[100], n, choice, searchKey;

    cout << "Enter number of students: ";
    cin >> n;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\nEnter roll numbers in random order:\n";
            for (int i = 0; i < n; i++)
                cin >> roll[i];

            cout << "Enter roll number to search: ";
            cin >> searchKey;

            if (linearSearch(roll, n, searchKey))
                cout << "Student attended the training program.\n";
            else
                cout << "Student did NOT attend the training program.\n";
            break;
        }

        case 2: {
            cout << "\nEnter roll numbers:\n";
            for (int i = 0; i < n; i++)
                cin >> roll[i];

            sort(roll, roll + n);
            cout << "\nRoll No. in Sorted Order: \n";

            for(int i =0 ; i < n; i++)
            {
                cout << roll[i] << "\n";
            }
            
            cout << "Enter roll number to search: ";
            cin >> searchKey;
        
            if (binarySearch(roll, n, searchKey))
                cout << "Student attended the training program.\n";
            else
                cout << "Student did NOT attend the training program.\n";
            break;
        }

        case 3:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
