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
        head = newNode;
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to make list circular (optional)
void makeCircular()
{
    if (head == NULL)
        return;
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head; // last node points to head
}

// Function to check if linked list is circular
bool isCircular()
{
    if (head == NULL)
        return false;

    Node *temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;

    if (temp == head)
        return true; // reached back to head → circular
    else
        return false; // reached NULL → not circular
}

// Display function
void display()
{
    Node *temp = head;
    cout << "Linked List: ";
    int count = 0; // avoid infinite loop if circular
    while (temp != NULL && count < 10)
    {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    cout << endl;
}

// ---------------- MAIN ----------------
int main()
{
    // Create simple linked list
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    display();

    // Uncomment this line to make it circular
    // makeCircular();

    if (isCircular())
        cout << "The linked list is CIRCULAR.\n";
    else
        cout << "The linked list is NOT circular.\n";

    return 0;
}
