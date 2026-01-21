/*Given the root of a binary tree, return the sum of all left leaves. A leaf is a node with no
children. A left leaf is a leaf that is the left child of another node.
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
*/
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode *node)
{
    return node != NULL && node->left == NULL && node->right == NULL;
}

int sumOfLeftLeaves(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int sum = 0;

    if (isLeaf(root->left))
        sum += root->left->val;
    else
        sum += sumOfLeftLeaves(root->left);

    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main()
{

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Sum of all left leaves: " << sumOfLeftLeaves(root) << endl;

    return 0;
}
