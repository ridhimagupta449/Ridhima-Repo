#include<iostream>
using namespace std;

#define MAX 5

class Stack
{
    int arr[MAX];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push " << x << endl;
        }
        else
        {
            arr[++top] = x;
            cout << x << " pushed into stack." << endl;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Nothing to pop." << endl;
        }
        else
        {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Nothing at top." << endl;
        }
        else
        {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return (top == MAX - 1);
    }
};

int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. isEmpty" << endl;
        cout << "6. isFull" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            if (s.isEmpty())
                cout << "Stack is Empty." << endl;
            else
                cout << "Stack is not Empty." << endl;
            break;
        case 6:
            if (s.isFull())
                cout << "Stack is Full." << endl;
            else
                cout << "Stack is not Full." << endl;
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
