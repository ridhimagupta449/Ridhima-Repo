/*Given in-order and post-order traversals, write a program to construct the Binary Tree.*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *buildTreeHelper(vector<int> &inorder, int inStart, int inEnd,
                      vector<int> &postorder, int postStart, int postEnd,
                      unordered_map<int, int> &inMap)
{
    if (inStart > inEnd || postStart > postEnd)
        return NULL;

    Node *root = new Node(postorder[postEnd]);

    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeHelper(inorder, inStart, inRoot - 1,
                                 postorder, postStart, postStart + numsLeft - 1, inMap);
    root->right = buildTreeHelper(inorder, inRoot + 1, inEnd,
                                  postorder, postStart + numsLeft, postEnd - 1, inMap);

    return root;
}

Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
        inMap[inorder[i]] = i;

    return buildTreeHelper(inorder, 0, inorder.size() - 1,
                           postorder, 0, postorder.size() - 1, inMap);
}

void printPreorder(Node *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    int n;
    cin >> n;

    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    Node *root = buildTree(inorder, postorder);

    cout << "Preorder Traversal of Constructed Tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}