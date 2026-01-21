#include <iostream>
using namespace std;

class stack {
public:
    int max = 100;
    int element[100];
    int top;

    stack() {
        top = -1;
    }

    bool isempty() {
        return (top == -1);
    }

    bool isfull() {
        return (top == max - 1);
    }

    int peek() {
        if (isempty()) {
            cout << "Empty stack\n";
            return -1;
        }
        return element[top];
    }

    void push(int x) {
        if (isfull()) {
            cout << "Overflow\n";
        } else {
            ++top;
            element[top] = x;
        }
    }

    void pop() {
        if (isempty()) {
            cout << "Underflow\n";
        } else {
            --top;
        }
    }

    // Pass result array as argument
    void result(int a[5], int b[5]) {
        stack f;
        for (int i = 0; i < 5; i++) {
            if (f.isempty()) {
                b[i] = -1;
                f.push(a[i]);
            } 
            else {
                while (!f.isempty()) {
                    if (a[i] > f.peek()) {
                        b[i] = f.peek();
                        f.push(a[i]);
                        break;
                    } 
                    else {
                        f.pop();
                    }
                }
                if (f.isempty()) {
                    b[i] = -1;
                    f.push(a[i]);
                }
            }
        }
    }
};

int main() {
    int r[5] = {4, 5, 2, 10, 8};
    int brr[5];  // output array
    stack s;

    s.result(r, brr); // pass both arrays

    cout << "Result: ";
    for (int i = 0; i < 5; i++) {
        cout << brr[i] << " ";
    }
    cout << endl;

    return 0;
}
