#include <iostream>
using namespace std;

#define MAX 5 // maximum size of queue

int queue[MAX];
int front = -1, rear = -1;

// Check if queue is empty
bool isEmpty()
{
    return (front == -1 && rear == -1);
}

// Check if queue is full
bool isFull()
{
    return (rear == MAX - 1);
}

// Enqueue operation
void enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue is FULL! Cannot insert " << x << endl;
    }
    else
    {
        if (front == -1)
            front = 0; // first element
        rear++;
        queue[rear] = x;
        cout << x << " enqueued successfully." << endl;
    }
}

// Dequeue operation
void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is EMPTY! Nothing to dequeue." << endl;
    }
    else
    {
        cout << queue[front] << " dequeued successfully." << endl;
        if (front == rear)
        {
            front = rear = -1; // queue becomes empty
        }
        else
        {
            front++;
        }
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
    }
    else
    {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n=== Queue Menu ===" << endl;
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
