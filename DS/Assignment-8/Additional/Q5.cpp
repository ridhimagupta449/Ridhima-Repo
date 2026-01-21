/*Given preorder and in-order traversals, write a program to construct the Binary Tree.*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *buildTreeHelper(vector<int> &preorder, int preStart, int preEnd,
                      vector<int> &inorder, int inStart, int inEnd,
                      unordered_map<int, int> &inMap)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    Node *root = new Node(preorder[preStart]);

    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                 inorder, inStart, inRoot - 1, inMap);
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                  inorder, inRoot + 1, inEnd, inMap);
    return root;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }
    return buildTreeHelper(preorder, 0, preorder.size() - 1,
                           inorder, 0, inorder.size() - 1, inMap);
}

void printPostorder(Node *root)
{
    if (!root)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int main()
{
    int n;
    cin >> n;

    vector<int> preorder(n), inorder(n);

    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    Node *root = buildTree(preorder, inorder);

    cout << "Postorder Traversal of Constructed Tree: ";
    printPostorder(root);
    cout << endl;

    return 0;
}