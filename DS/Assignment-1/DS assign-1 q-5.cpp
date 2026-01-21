#include <iostream>
using namespace std;

int main() {
    int a, b;
    int arr[10][10];   

    cout << "Enter number of rows and columns: ";
    cin >> a >> b;

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << "\nMatrix:\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nSum of each row:\n";
    for (int i = 0; i < a; i++) {
        int aSum = 0;
        for (int j = 0; j < b; j++) {
            aSum += arr[i][j];
        }
        cout << "Row " << i + 1 << " sum = " << aSum << endl;
    }

    cout << "\nSum of each column:\n";
    for (int j = 0; j < b; j++) {
        int bSum = 0;
        for (int i = 0; i < a; i++) {
            bSum += arr[i][j];
        }
        cout << "Column " << j + 1 << " sum = " << bSum << endl;
    }

    return 0;
}

