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
        //stack f;
        for(int i=0;i<4;i++){
            int j=i+1;
            if(a[j]>a[i]){
                b[i]=a[j];
            }
            else{
                b[i]=-1;
            }
        }
        b[4]=-1;
        cout << "Result: ";
        for (int i = 0; i < 5; i++) {
            cout << b[i] << " ";
        }
    }
};

int main() {
    int r[5] = {6,8,0,1,3};
    int brr[5];  // output array
    stack s;

    s.result(r, brr); // pass both arrays
    cout << endl;

    return 0;
}
