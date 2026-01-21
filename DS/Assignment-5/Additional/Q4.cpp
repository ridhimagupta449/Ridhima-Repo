#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

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

Node *rotateLeft(Node *head, int k)
{
    if (head == NULL || k == 0)
        return head;

    Node *temp = head;
    int len = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }

    k = k % len;
    if (k == 0)
        return head;

    temp->next = head;

    Node *newTail = head;
    for (int i = 1; i < k; i++)
        newTail = newTail->next;

    Node *newHead = newTail->next;

     newTail->next = NULL;

    return newHead;
}

int main()
{
    Node *head = NULL;
    int n, val, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter linked list elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertEnd(&head, val);
    }

    cout << "Enter k (number of rotations): ";
    cin >> k;

    cout << "\nOriginal list: ";
    printList(head);

    head = rotateLeft(head, k);

    cout << "List after rotating left by " << k << ": ";
    printList(head);

    return 0;
}
