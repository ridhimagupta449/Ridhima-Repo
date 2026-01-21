#include <iostream>
using namespace std;

class Stack {
private:
    char arr[100]; 
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    void push(char c) {
        if (topIndex < 99) {
            arr[++topIndex] = c;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }

    void pop() {
        if (topIndex >= 0) {
            topIndex--;
        } else {
            cout << "Stack Underflow!" << endl;
        }
    }

    char top() {
        if (topIndex >= 0) {
            return arr[topIndex];
        }
        return '\0';
    }

    bool empty() {
        return topIndex == -1;
    }
};

bool isBalanced(string expr) {
    Stack s;

    // ? replaced range-based for loop with normal loop
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty())
                return false;

            char topChar = s.top();
            s.pop();

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return s.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced Expression" << endl;
    else
        cout << "Unbalanced Expression" << endl;

    return 0;
}

