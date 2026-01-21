#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// Function to insert node at end
void insertEnd(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse nodes in groups of K
Node *reverseInGroups(Node *head, int k)
{
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;
    int count = 0;

    // Reverse first k nodes
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // next now points to (k+1)th node
    if (next != NULL)
        head->next = reverseInGroups(next, k); // recursive call

    // prev is new head of this part
    return prev;
}

int main()
{
    Node *head = NULL;
    int n, k, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter linked list elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insertEnd(&head, value);
    }

    cout << "Enter group size k: ";
    cin >> k;

    cout << "\nOriginal list: ";
    printList(head);

    head = reverseInGroups(head, k);

    cout << "Reversed list in groups of " << k << ": ";
    printList(head);

    return 0;
}
