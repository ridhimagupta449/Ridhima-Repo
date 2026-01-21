#include <iostream> 
using namespace std;
int main() {
    int n, i, j, k, arr[100], count = 0;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array:" << endl;
    for (i = 0; i < n; i++) {   
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] - arr[j]== k||arr[i]-arr[j]==-k) { 
                
                count++;
            }
        }
    }

    cout << "\nTotal number of pairs = " << count << endl;

    return 0;
}

