/*Write a program for binary search tree (BST) having functions for the following
operations:
(a) Insert an element (no duplicates are allowed),
(b) Delete an existing element,
(c) Maximum depth of BST
(d) Minimum depth of BST*/
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

// Insert a node (No duplicates allowed)
Node *insertNode(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insertNode(root->left, val);
    else if (val > root->data)
        root->right = insertNode(root->right, val);
    else
        cout << "Duplicate value ignored: " << val << endl;

    return root;
}

// Find minimum node in right subtree (used in delete)
Node *findMin(Node *root)
{
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node
Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
        return root;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else
    {
        // Node with 1 or no child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with 2 children: Replace with inorder successor
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Maximum Depth of BST
int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

// Minimum Depth of BST
int minDepth(Node *root)
{
    if (root == NULL)
        return 0;

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    if (root->left == NULL)
        return rightDepth + 1;
    if (root->right == NULL)
        return leftDepth + 1;

    return min(leftDepth, rightDepth) + 1;
}

int main()
{
    Node *root = NULL;
    int choice, val;

    while (true)
    {
        cout << "\n1. Insert\n2. Delete\n3. Max Depth\n4. Min Depth\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            root = insertNode(root, val);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteNode(root, val);
            break;

        case 3:
            cout << "Maximum Depth: " << maxDepth(root) << endl;
            break;

        case 4:
            cout << "Minimum Depth: " << minDepth(root) << endl;
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
