#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Function to insert node at end
void insertEnd(int val)
{
    Node *newNode = new Node{val, NULL};
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head; // points to itself
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head; // complete the circle
    }
}

// Function to display list with head node repeated at end
void display()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    Node *temp = head;
    cout << "Circular Linked List: ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl; // repeat head node value at end
}

int main()
{
    // Inserting given nodes
    insertEnd(20);
    insertEnd(100);
    insertEnd(40);
    insertEnd(80);
    insertEnd(60);

    // Display result
    display();

    return 0;
}
