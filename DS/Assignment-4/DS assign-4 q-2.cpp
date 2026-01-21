#include <iostream>
using namespace std;

#define MAX 5 // maximum size of queue

int queue[MAX];
int front = -1, rear = -1;

// Check if queue is empty
bool isEmpty()
{
    return (front == -1);
}

// Check if queue is full
bool isFull()
{
    return ((rear + 1) % MAX == front);
}

// Enqueue operation
void enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue is FULL! Cannot insert " << x << endl;
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = x;
    cout << x << " enqueued successfully." << endl;
}

// Dequeue operation
void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is EMPTY! Nothing to dequeue." << endl;
        return;
    }
    cout << queue[front] << " dequeued successfully." << endl;
    if (front == rear)
    {
        front = rear = -1; // queue becomes empty
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// Peek front element
void peek()
{
    if (isEmpty())
    {
        cout << "Queue is EMPTY! No front element." << endl;
    }
    else
    {
        cout << "Front element: " << queue[front] << endl;
    }
}

// Display queue elements
void display()
{
    if (isEmpty())
    {
        cout << "Queue is EMPTY!" << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true)
    {
        cout << queue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n=== Circular Queue Menu ===" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << (isEmpty() ? "Queue is EMPTY." : "Queue is NOT EMPTY.") << endl;
            break;
        case 6:
            cout << (isFull() ? "Queue is FULL." : "Queue is NOT FULL.") << endl;
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
