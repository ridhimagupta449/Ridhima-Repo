#include <iostream>
using namespace std;

class SpecialStack {
    int arr[100];   // fixed size for simplicity
    int topIndex;
    int minElement;

public:
    SpecialStack() {
        topIndex = -1;
        minElement = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == 99;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        if (isEmpty()) {
            topIndex++;
            arr[topIndex] = x;
            minElement = x;
        }
        else if (x >= minElement) {
            topIndex++;
            arr[topIndex] = x;
        }
        else {
            // encode value
            int encoded = 2 * x - minElement;
            topIndex++;
            arr[topIndex] = encoded;
            minElement = x;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        int topVal = arr[topIndex];
        if (topVal >= minElement) {
            // normal pop
            topIndex--;
        }
        else {
            // encoded value ? restore previous min
            minElement = 2 * minElement - topVal;
            topIndex--;
        }
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        int topVal = arr[topIndex];
        if (topVal >= minElement)
            return topVal;
        else
            return minElement; // real value
    }

    int getMin() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return minElement;
    }
};

int main() {
    SpecialStack st;

    st.push(5);
    st.push(2);
    st.push(10);
    st.push(1);

    cout << "Current Min: " << st.getMin() << endl; // 1
    st.pop();
    cout << "Current Min: " << st.getMin() << endl; // 2
    st.pop();
    cout << "Top: " << st.top() << endl;            // 2
    cout << "Current Min: " << st.getMin() << endl; // 2

    return 0;
}
