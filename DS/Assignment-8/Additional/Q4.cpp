/*There are different ways to look at a binary tree. The right view of a binary tree contains
the set of nodes that will be visible if you look at the binary tree from the right side. Given
the root node of a binary tree, return an array containing the node elements in the right view,
from top to bottom.
Testing
Input Format
The first line contains an integer T denoting the number of test cases.
For each test case, the input has 2 lines:
The first line contains an integer n denoting the number of nodes in the tree (including the
NULL nodes).
The second line contains n space-separated integers that will form the binary tree. The
integers follow level order traversal of the tree where -1 indicates a NULL node.
Output Format
For each test case, the output contains a line with space-separated integers representing the
right view of the binary tree.*/
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

vector<int> rightView(Node *root)
{
    vector<int> result;
    if (!root)
        return result;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            if (i == size - 1)
                result.push_back(node->val);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return result;
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
        vector<int> view = rightView(root);

        for (int val : view)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}