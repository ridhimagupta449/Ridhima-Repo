/*Given a binary tree, return its maximum depth. The depth of a binary tree is the number
of nodes from the root node to any of the leaf nodes. The maximum depth is the maximum of
the depths across all the paths.
Testing
Input Format
The first line contains an integer T denoting the number of test cases.
For each test case, the input has 2 lines:
The first line contains an integer n denoting the number of nodes in the tree (including the
NULL nodes).
The second line contains n space-separated integers that will form the binary tree. The
integers follow level order traversal of the tree where -1 indicates a NULL node.
Output Format
For each test case, the output has an integer denoting the maximum depth of the tree. */
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *buildTree(vector<int> &arr)
{
    if (arr.empty() || arr[0] == -1)
        return NULL;

    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        Node *curr = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != -1)
        {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1)
        {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Node *root = buildTree(arr);
        cout << maxDepth(root) << endl;
    }
    return 0;
}