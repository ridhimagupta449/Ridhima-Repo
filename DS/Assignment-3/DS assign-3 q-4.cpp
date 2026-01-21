#include <iostream>
#include <string>
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
        if (!empty()) {
            topIndex--;
        } else {
            cout << "Stack Underflow!" << endl;
        }
    }

    char top() {
        if (!empty()) {
            return arr[topIndex];
        }
        return '\0';
    }

    bool empty() {
        return topIndex == -1;
    }
};

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s) {
    Stack st;
    string res = "";

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            res += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else {
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;

    cout << "Postfix expression: " << infixToPostfix(exp) << endl;
    return 0;
}
