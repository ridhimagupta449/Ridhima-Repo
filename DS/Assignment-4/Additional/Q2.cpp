/*Given a queue with random elements, we need to sort it. We are not allowed to use extra space. The
operations allowed on queue are:
       1.   enqueue() : Adds an item to rear of queue.
2. dequeue() : Removes an item from front of queue.
3. isEmpty() : Checks if a queue is empty.
Input: 11, 5, 4, 21
Output: 4, 5, 11, 21 */
#include <iostream>
using namespace std;

class Queue
{
    int arr[100];
    int front, rear, size;

public:
    Queue()
    {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int x)
    {
        arr[++rear] = x;
        size++;
    }

    int dequeue()
    {
        int x = arr[front++];
        size--;
        return x;
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    int getSize()
    {
        return size;
    }

    int getFront()
    {
        return arr[front];
    }
};

// Function to get minimum element index in first 'n' elements
int minIndex(Queue &q, int n)
{
    int min_index = -1;
    int min_val = 1e9;
    int size = q.getSize();

    for (int i = 0; i < size; i++)
    {
        int curr = q.dequeue();

        // check only first n elements
        if (i < n && curr <= min_val)
        {
            min_val = curr;
            min_index = i;
        }
        q.enqueue(curr);
    }
    return min_index;
}

// Move min element to rear of queue
void insertMinToRear(Queue &q, int min_index, int n)
{
    int min_val;
    int size = q.getSize();

    for (int i = 0; i < size; i++)
    {
        int curr = q.dequeue();

        if (i == min_index && i < n)
        {
            min_val = curr;
        }
        else
        {
            q.enqueue(curr);
        }
    }
    q.enqueue(min_val);
}

// Sort queue
void sortQueue(Queue &q)
{
    for (int i = 1; i <= q.getSize(); i++)
    {
        int min_index = minIndex(q, q.getSize() - i + 1);
        insertMinToRear(q, min_index, q.getSize() - i + 1);
    }
}

int main()
{
    Queue q;
    q.enqueue(11);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(21);

    sortQueue(q);

    cout << "Sorted Queue: ";
    while (!q.isEmpty())
    {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    return 0;
}