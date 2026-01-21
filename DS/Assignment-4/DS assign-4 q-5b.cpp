#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

// Push operation
void push(int x)
{
    int size = q.size();
    q.push(x);

    // Rotate elements so new element comes at front
    for (int i = 0; i < size; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

// Pop operation
void pop()
{
    if (q.empty())
    {
        cout << "Stack is EMPTY!" << endl;
    }
    else
    {
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }
}

// Top operation
void top()
{
    if (q.empty())
    {
        cout << "Stack is EMPTY!" << endl;
    }
    else
    {
        cout << "Top element: " << q.front() << endl;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    top(); // 30
    pop(); // removes 30
    top(); // 20
    pop(); // removes 20
    top(); // 10

    return 0;
}
