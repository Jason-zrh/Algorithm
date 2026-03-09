#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // 1. 如果 t1 为空，合并后的结果显然就是 t2
        if (!t1) return t2;
        // 2. 如果 t2 为空，合并后的结果显然就是 t1
        if (!t2) return t1;

        // 3. 此时 t1 和 t2 都不为空，合并值
        t1->val += t2->val;

        // 4. 递归合并左子树，并将返回的新根节点挂在 t1 的左边
        t1->left = mergeTrees(t1->left, t2->left);
        // 5. 递归合并右子树，并将返回的新根节点挂在 t1 的右边
        t1->right = mergeTrees(t1->right, t2->right);

        // 返回合并后的根节点
        return t1;
    }
};