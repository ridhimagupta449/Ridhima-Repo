#include <iostream>
using namespace std;

// ---------------- DOUBLY LINKED LIST ----------------
struct DNode
{
    int data;
    DNode *prev, *next;
};

DNode *dHead = NULL;

// Insert node at end
void insertDoubly(int val)
{
    DNode *newNode = new DNode{val, NULL, NULL};
    if (dHead == NULL)
        dHead = newNode;
    else
    {
        DNode *temp = dHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Count size of doubly linked list
int sizeDoubly()
{
    int count = 0;
    DNode *temp = dHead;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// ---------------- CIRCULAR LINKED LIST ----------------
struct CNode
{
    int data;
    CNode *next;
};

CNode *cHead = NULL;

// Insert node at end
void insertCircular(int val)
{
    CNode *newNode = new CNode{val, NULL};
    if (cHead == NULL)
    {
        cHead = newNode;
        newNode->next = cHead; // first node points to itself
    }
    else
    {
        CNode *temp = cHead;
        while (temp->next != cHead)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = cHead; // complete the circle
    }
}

// Count size of circular linked list
int sizeCircular()
{
    if (cHead == NULL)
        return 0;
    int count = 0;
    CNode *temp = cHead;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != cHead);
    return count;
}

// ---------------- MAIN ----------------
int main()
{
    // Create a Doubly Linked List: 10 -> 20 -> 30
    insertDoubly(10);
    insertDoubly(20);
    insertDoubly(30);

    // Create a Circular Linked List: 5 -> 15 -> 25 -> 35
    insertCircular(5);
    insertCircular(15);
    insertCircular(25);
    insertCircular(35);

    cout << "Size of Doubly Linked List = " << sizeDoubly() << endl;
    cout << "Size of Circular Linked List = " << sizeCircular() << endl;

    return 0;
}
