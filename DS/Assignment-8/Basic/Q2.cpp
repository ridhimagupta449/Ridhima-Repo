/* Implement following functions for Binary Search Trees
(a) Search a given item (Recursive & Non-Recursive)
(b) Maximum element of the BST
(c) Minimum element of the BST
(d) In-order successor of a given node the BST
(e) In-order predecessor of a given node the BST*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Create new node
Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
Node *insert(Node *root, int data)
{
    if (!root)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// (a) Recursive Search
Node *searchRec(Node *root, int key)
{
    if (!root || root->data == key)
        return root;
    if (key < root->data)
        return searchRec(root->left, key);
    return searchRec(root->right, key);
}

// (a) Non-Recursive Search
Node *searchNonRec(Node *root, int key)
{
    while (root)
    {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// (b) Maximum element in BST
Node *findMax(Node *root)
{
    if (!root)
        return NULL;
    while (root->right)
        root = root->right;
    return root;
}

// (c) Minimum element in BST
Node *findMin(Node *root)
{
    if (!root)
        return NULL;
    while (root->left)
        root = root->left;
    return root;
}

// (d) In-order Successor (smallest element in right subtree)
Node *inorderSuccessor(Node *root, Node *node)
{
    if (!node)
        return NULL;

    // If right subtree exists → successor is its leftmost node
    if (node->right)
        return findMin(node->right);

    // Else successor is one of the ancestors
    Node *successor = NULL;
    while (root)
    {
        if (node->data < root->data)
        {
            successor = root;
            root = root->left;
        }
        else if (node->data > root->data)
        {
            root = root->right;
        }
        else
            break;
    }
    return successor;
}

// (e) In-order Predecessor (largest element in left subtree)
Node *inorderPredecessor(Node *root, Node *node)
{
    if (!node)
        return NULL;

    // If left subtree exists → predecessor is its rightmost node
    if (node->left)
        return findMax(node->left);

    // Else predecessor is one of the ancestors
    Node *predecessor = NULL;
    while (root)
    {
        if (node->data > root->data)
        {
            predecessor = root;
            root = root->right;
        }
        else if (node->data < root->data)
        {
            root = root->left;
        }
        else
            break;
    }
    return predecessor;
}

// Inorder print (for checking)
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    int n, val, key;

    cout << "Enter number of nodes in BST: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    // Search
    cout << "\n\nEnter value to search: ";
    cin >> key;

    Node *foundRec = searchRec(root, key);
    cout << "Recursive Search: "
         << (foundRec ? "Found" : "Not Found") << endl;

    Node *foundNonRec = searchNonRec(root, key);
    cout << "Non-Recursive Search: "
         << (foundNonRec ? "Found" : "Not Found") << endl;

    // Min & Max
    cout << "\nMinimum Element: "
         << (findMin(root) ? findMin(root)->data : -1) << endl;
    cout << "Maximum Element: "
         << (findMax(root) ? findMax(root)->data : -1) << endl;

    // Successor & Predecessor
    if (foundRec)
    {
        Node *succ = inorderSuccessor(root, foundRec);
        Node *pred = inorderPredecessor(root, foundRec);

        cout << "In-order Successor of " << key << ": "
             << (succ ? to_string(succ->data) : "None") << endl;
        cout << "In-order Predecessor of " << key << ": "
             << (pred ? to_string(pred->data) : "None") << endl;
    }
    else
    {
        cout << "Successor/Predecessor not applicable since element not found.\n";
    }

    return 0;
}
