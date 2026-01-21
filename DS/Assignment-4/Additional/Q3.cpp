/*Given a Queue consisting of first n natural numbers (in random order). The task is to check whether
the given Queue elements can be arranged in increasing order in another Queue using a stack. The
operation allowed are:
1. Push and pop elements from the stack
2. Pop (Or Dequeue) from the given Queue.
3. Push (Or Enqueue) in the another Queue.
Input : Queue[] = { 5, 1, 2, 3, 4 }
Output : Yes*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSorted(queue<int> &q)
{
    stack<int> st;
    queue<int> q2;

    int expected = 1;
    int n = q.size();

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        if (front == expected)
        {
            q2.push(front);
            expected++;
        }
        else
        {
            while (!st.empty() && st.top() == expected)
            {
                q2.push(st.top());
                st.pop();
                expected++;
            }

            st.push(front);
        }
    }

    while (!st.empty() && st.top() == expected)
    {
        q2.push(st.top());
        st.pop();
        expected++;
    }

    return (expected - 1 == n);
}

int main()
{
    queue<int> q;

    int arr[] = {5, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        q.push(arr[i]);

    if (checkSorted(q))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
