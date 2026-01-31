#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> array;
    void Inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        Inorder(root->left);
        array.push_back(root->val);
        Inorder(root->right);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        Inorder(root);
        return array[k - 1];
    }
};