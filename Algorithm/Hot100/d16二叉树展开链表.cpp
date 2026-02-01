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

// 将根节点的左子树插到右边
void dfs(TreeNode *root)
{
    if (root == nullptr)
        return;

    // 1. 如果有左子树，才需要“搬运”操作
    if (root->left != nullptr)
    {
        TreeNode *originalRight = root->right; // 暂存原来的右子树

        // 将左子树切断并挪到右边
        root->right = root->left;
        root->left = nullptr; // 关键点：一定要置空，防止死循环和结构错误   !!!!!!!!!!! 踩坑点 !!!!!!!!!!!

        // 找新右子树（原左子树）的最末尾
        TreeNode *tail = root->right;
        while (tail->right)
        {
            tail = tail->right;
        }

        // 把原来的右子树接在末尾
        tail->right = originalRight;
    }

    // 2. 依次递归处理现在的右子树
    dfs(root->left);
    dfs(root->right);
}

void flatten(TreeNode *root)
{
    dfs(root);
}