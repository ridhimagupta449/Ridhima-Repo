/*Write a program to merge two BSTs into a doubly-linked list in sorted order.*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void bstToDLL(Node *root, Node *&head, Node *&prev)
{
    if (!root)
        return;

    bstToDLL(root->left, head, prev);

    if (!prev)
        head = root;
    else
    {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    bstToDLL(root->right, head, prev);
}

Node *mergeDLL(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    Node *head = NULL;
    Node *tail = NULL;

    while (head1 && head2)
    {
        Node *smaller;
        if (head1->val < head2->val)
        {
            smaller = head1;
            head1 = head1->right;
        }
        else
        {
            smaller = head2;
            head2 = head2->right;
        }

        if (!head)
        {
            head = smaller;
            tail = smaller;
        }
        else
        {
            tail->right = smaller;
            smaller->left = tail;
            tail = smaller;
        }
    }

    while (head1)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

void printDLL(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;

    int n1, n2;
    cout << "Enter number of nodes in BST1: ";
    cin >> n1;
    cout << "Enter elements of BST1: ";
    for (int i = 0; i < n1; i++)
    {
        int val;
        cin >> val;
        root1 = insert(root1, val);
    }

    cout << "Enter number of nodes in BST2: ";
    cin >> n2;
    cout << "Enter elements of BST2: ";
    for (int i = 0; i < n2; i++)
    {
        int val;
        cin >> val;
        root2 = insert(root2, val);
    }

    Node *head1 = NULL, *prev1 = NULL;
    bstToDLL(root1, head1, prev1);
    Node *head2 = NULL, *prev2 = NULL;
    bstToDLL(root2, head2, prev2);

    Node *mergedHead = mergeDLL(head1, head2);

    cout << "Merged Doubly Linked List in Sorted Order: ";
    printDLL(mergedHead);

    return 0;
}