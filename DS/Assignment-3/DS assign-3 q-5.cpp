
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;

    stack<int> st;

    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];

        // if operand, push to stack
        if (isdigit(c))
        {
            st.push(c - '0'); // convert char to int
        }
        else
        { 
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            switch (c)
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            }
        }
    }

    cout << "Result = " << st.top() << endl;
    return 0;
}
