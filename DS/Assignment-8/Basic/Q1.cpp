/* Write program using functions for binary tree traversals: Pre-order, In-order and Post
order using recursive approach.*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *buildTree()
{
    int value;
    cout << "Enter value (-1 for no node): ";
    cin >> value;

    if (value == -1)
        return NULL;

    Node *root = createNode(value);

    cout << "Enter left child of " << value << ":\n";
    root->left = buildTree();

    cout << "Enter right child of " << value << ":\n";
    root->right = buildTree();

    return root;
}

// Recursive Pre-order traversal
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Recursive In-order traversal
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Recursive Post-order traversal
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    cout << "Build the Binary Tree\n";
    Node *root = buildTree();

    cout << "\nPre-order Traversal: ";
    preorder(root);

    cout << "\nIn-order Traversal: ";
    inorder(root);

    cout << "\nPost-order Traversal: ";
    postorder(root);

    cout << endl;
    return 0;
}
