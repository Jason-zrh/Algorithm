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


// 递归写法
class Solution
{
public:
    // 递归函数的作用: 给出该节点的中序遍历
    vector<int> ret;
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorderTraversal(root->left);
        ret.push_back(root->val);
        inorderTraversal(root->right);
    }



    vector<int> inorderTraversal(TreeNode *root)
    {
        dfs(root);
        return ret;
    }
};

int main()
{

    return 0;
}