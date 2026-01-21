#include <iostream>
using namespace std;
int main() {
    int arr[100], n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    //1.Reverse
    
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    
    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
        
       //b.matrix multiplication
    int A[10][10], B[10][10], C[10][10];
    int x, y, p, q;
    
    cout << "\nEnter rows and cols of Matrix A: ";
    cin >> x>>y;
    
    cout << "\nEnter rows and cols of Matrix B: ";
    cin >> p >> q;

    if (y != p) {
        cout << "\nMatrix multiplication not possible!";
        return 0;
    }

    cout << "\nEnter elements of Matrix A:\n";
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> A[i][j];

    cout << "\nEnter elements of Matrix B:\n";
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            cin >> B[i][j];


    for (int i = 0; i < x; i++)
        for (int j = 0; j < q; j++)
            C[i][j] = 0;
        
        
    for (int i = 0; i < x; i++)
        for (int j = 0; j < q; j++)
            for (int k = 0; k < y; k++)
                C[i][j] += A[i][k] * B[k][j];

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < q; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    //3.matrix transpose
	   int O[10][10], T[10][10];
    int c,d ;

    cout << "\nEnter rows and cols of Matrix: ";
    cin >> c>> d;

    cout << "\nEnter elements of Matrix:\n";
    for (int i = 0; i < c; i++)
        for (int j = 0; j < d; j++)
            cin >> A[i][j];

    for (int i = 0; i < c; i++)
        for (int j = 0; j < d; j++)
            T[j][i] = A[i][j];

    cout << "Transpose Matrix:\n";
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < c; j++)
            cout << T[i][j] << " ";
        cout << endl;
    }

    return 0;
}

 
