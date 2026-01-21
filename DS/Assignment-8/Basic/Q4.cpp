/*Write a program to determine whether a given binary tree is a BST or not.*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node *createNode(int val)
{
    return new Node(val);
}

bool isBSTUtil(Node *root, int minVal, int maxVal)
{
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node *root)
{
    return isBSTUtil(root, -100000, 100000);
}

int main()
{

    Node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(1);
    root->left->right = createNode(7);
    root->right->right = createNode(20);

    if (isBST(root))
        cout << "The tree is a BST" << endl;
    else
        cout << "The tree is NOT a BST" << endl;

    return 0;
}
