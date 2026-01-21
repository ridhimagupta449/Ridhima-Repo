#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q)
{
    int n = q.size();
    if (n % 2 != 0)
    {
        cout << "Queue has odd number of elements, cannot interleave properly!" << endl;
        return;
    }

    int half = n / 2;
    queue<int> firstHalf;

    // Move first half into another queue
    for (int i = 0; i < half; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }

    // Interleave elements
    while (!firstHalf.empty())
    {
        q.push(firstHalf.front()); // from first half
        firstHalf.pop();

        q.push(q.front()); // from second half
        q.pop();
    }
}

int main()
{
    queue<int> q;
    int n, x;

    cout << "Enter number of elements (even): ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
