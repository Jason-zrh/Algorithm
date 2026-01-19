#include <iostream>

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
    int ans = 0;

    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int left = depth(root->left);
        int right = depth(root->right);

        // 更新直径（经过当前节点）
        ans = std::max(ans, left + right);

        // 返回当前子树最大深度
        return std::max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        depth(root);
        return ans;
    }
};

int main()
{
    return 0;
}