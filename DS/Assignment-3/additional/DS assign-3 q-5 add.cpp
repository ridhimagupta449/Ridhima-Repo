#include <iostream>
using namespace std;

// Bubble sort to sort array B
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Simple stack using array
class Stack {
    int arr[100];
    int topIndex;

public:
    Stack() { topIndex = -1; }

    void push(int x) {
        arr[++topIndex] = x;
    }

    void pop() {
        topIndex--;
    }

    int top() {
        return arr[topIndex];
    }

    bool empty() {
        return (topIndex == -1);
    }
};

bool canTransform(int A[], int N) {
    int B[100];
    for (int i = 0; i < N; i++) {
        B[i] = A[i];
    }

    // sort B using bubble sort
    bubbleSort(B, N);

    Stack S;
    int j = 0; 

    // simulate operations
    for (int i = 0; i < N; i++) {
        // operation (a): push from A to stack
        S.push(A[i]);

        // operation (b): keep popping if top matches next sorted element
        while (!S.empty() && S.top() == B[j]) {
            S.pop();
            j++;
        }
    }

    return (S.empty() && j == N);
}

int main() {
    int N;
    cout << "Enter size of array: ";
    cin >> N;

    int A[100];
    cout << "Enter elements of array A: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    if (canTransform(A, N))
        cout << "Yes, possible to transform A into sorted B.\n";
    else
        cout << "No, not possible.\n";

    return 0;
}

