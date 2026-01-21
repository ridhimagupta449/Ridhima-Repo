#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int getLength(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

Node *getIntersectionNode(Node *headA, Node *headB)
{
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    while (lenA > lenB)
    {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA)
    {
        headB = headB->next;
        lenB--;
    }

    while (headA != NULL && headB != NULL)
    {
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
}

int main()
{

    Node *intersect = new Node{8, new Node{5, NULL}};

    // List A
    Node *headA = new Node{4, new Node{1, intersect}};

    // List B
    Node *headB = new Node{5, new Node{6, new Node{1, intersect}}};

    // Find intersection
    Node *result = getIntersectionNode(headA, headB);

    if (result != NULL)
        cout << "Intersected at " << result->data;
    else
        cout << "No intersection";

    return 0;
}
