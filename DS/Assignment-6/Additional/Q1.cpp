#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

void splitCircularList(Node *head, Node *&head1, Node *&head2)
{
    if (!head || head->next == head)
    {
        head1 = head;
        head2 = NULL;
        return;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    head1 = head;

    head2 = slow->next;

    slow->next = head1;

    if (fast->next == head)
        fast->next = head2;
    else
        fast->next->next = head2;
}

void printCircular(Node *head)
{
    if (!head)
        return;
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(4);
    head->next->next = new Node(9);
    head->next->next->next = head;

    Node *head1 = NULL;
    Node *head2 = NULL;

    splitCircularList(head, head1, head2);

    cout << "First Circular List: ";
    printCircular(head1);

    cout << "Second Circular List: ";
    printCircular(head2);

    return 0;
}
