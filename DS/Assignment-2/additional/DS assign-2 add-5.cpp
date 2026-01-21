#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[100];  
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 2) {
           
            if (i + 1 < n) arr[i + 1] = 2;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == 2 && arr[i + 1] != 2) {
            
            for (int j = n - 1; j > i + 1; j--) {
                arr[j] = arr[j - 1];
            }
            arr[i + 1] = 2;
            i++; 
        }
    }

    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

