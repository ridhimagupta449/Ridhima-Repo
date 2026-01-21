#include <iostream>
#include <queue>
using namespace std;

class StackTwoQ
{
    queue<int> q1, q2;

public:
    void push(int x)
    {
        // Put new element in q2
        q2.push(x);

        // Move everything from q1 to q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is EMPTY!" << endl;
            return;
        }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
    }

    void top()
    {
        if (q1.empty())
        {
            cout << "Stack is EMPTY!" << endl;
            return;
        }
        cout << "Top element: " << q1.front() << endl;
    }

    bool empty()
    {
        return q1.empty();
    }
};

